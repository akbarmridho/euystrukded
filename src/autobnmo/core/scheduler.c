#include "scheduler.h"

boolean AUTOBNMO_DEBUG = true;

void schedule(int target_food_id) {
    list_of_action_list_t action_steps;
    create_list_of_list_action(&action_steps);

    list_action_t actions;
    create_list_action(&actions);
    create_action_priority(&actions, target_food_id);

    if (AUTOBNMO_DEBUG) {
        printf("action priority length %d\n", actions.length);
    }

    group_list_action(&action_steps, actions);

    int grouped_steps_len = action_steps.length;
    list_of_action_list_t grouped_steps[grouped_steps_len];

    for (int i = 0; i < action_steps.length; i++) {
        create_list_of_list_action(&grouped_steps[i]);

        int boil_idx = -1;
        int chop_idx = -1;
        int mix_idx = -1;
        int fry_idx = -1;

        for (int j = 0; j < action_steps.contents[i].length; j++) {
            food_t food = action_steps.contents[i].contents[j]->food;
            list_action_t group;

            if (food.source == Boil) {
                if (boil_idx == -1) {
                    create_list_action(&group);
                    boil_idx = grouped_steps[i].length;
                    insert_list_of_list_action(&grouped_steps[i], group);
                }

                insert_list_action(&grouped_steps[i].contents[boil_idx], action_steps.contents[i].contents[j]);
            } else if (food.source == Chop) {
                if (chop_idx == -1) {
                    create_list_action(&group);
                    chop_idx = grouped_steps[i].length;
                    insert_list_of_list_action(&grouped_steps[i], group);
                }

                insert_list_action(&grouped_steps[i].contents[chop_idx], action_steps.contents[i].contents[j]);
            } else if (food.source == Mix) {
                if (mix_idx == -1) {
                    create_list_action(&group);
                    mix_idx = grouped_steps[i].length;
                    insert_list_of_list_action(&grouped_steps[i], group);
                }

                insert_list_action(&grouped_steps[i].contents[mix_idx], action_steps.contents[i].contents[j]);
            } else if (food.source == Fry) {
                if (fry_idx == -1) {
                    create_list_action(&group);
                    fry_idx = grouped_steps[i].length;
                    insert_list_of_list_action(&grouped_steps[i], group);
                }

                insert_list_action(&grouped_steps[i].contents[fry_idx], action_steps.contents[i].contents[j]);
            } else {
                printf("Invalid source on sheduler\n");
            }
        }
    }

    // lakukan sorting pada grouped_steps sedemikian sehingga terurut langkah-langkahnya sesuai dengan langkah
    // paling efisien. Travelling salesman problem

    setup_writer("autobnmo.txt");

    for (int i = 0; i < grouped_steps_len; i++) {
        list_of_action_list_t steps = grouped_steps[i];
        char buffer[28];

        for (int j = 0; j < steps.length; j++) {
            snprintf(buffer, 28, "%s %c\n", "AUTOMOVE", source_to_char(steps.contents[j].contents[0]->food.source));
            c_write(buffer);

            for (int k = 0; k < steps.contents[j].length; k++) {
                food_t food = steps.contents[j].contents[k]->food;
                snprintf(buffer, 28, "%s %d id\n", "AUTOPROCESS", food.id);
            }
        }
    }

    close_writer();
}

void group_list_action(list_of_action_list_t *list, list_action_t action_list) {
    int highest_priority = 0;

    for (int i = 0; i < action_list.length; i++) {
        if (action_list.contents[i]->priority > highest_priority) {
            highest_priority = action_list.contents[i]->priority;
        }
    }

    int current_highest_priority = highest_priority;

    while (current_highest_priority >= 0) {
        int highest_priority_count = 0;

        for (int i = 0; i < action_list.length; i++) {
            if (action_list.contents[i]->priority == current_highest_priority) {
                highest_priority_count++;
            }
        }

        list_action_t action_group;
        create_list_action(&action_group);
        boolean has_fry = false;
        boolean has_boil = false;
        boolean has_mix = false;
        boolean has_chop = false;

        while (highest_priority_count != 0) {
            int i = 0;
            boolean deleted = false;

            while (i < action_list.length && !deleted) {
                if (action_list.contents[i]->priority == current_highest_priority) {

                    if (action_list.contents[i]->food.source == Boil) {
                        has_boil = true;
                    } else if (action_list.contents[i]->food.source == Fry) {
                        has_fry = true;
                    } else if (action_list.contents[i]->food.source == Mix) {
                        has_mix = true;
                    } else if (action_list.contents[i]->food.source == Chop) {
                        has_chop = true;
                    }

                    insert_list_action(&action_group, action_list.contents[i]);

                    if (action_list.contents[i]->parent != NULL) {
                        action_list.contents[i]->parent->unmet_prereq_count--;
                    }

                    delete_list_action(&action_list, i);
                    highest_priority_count--;
                    deleted = true;
                } else {
                    i++;
                }
            }
        }

        int carry_count = 0;

        for (int i = 0; i < action_list.length; i++) {
            if (action_list.contents[i]->priority != current_highest_priority &&
                action_list.contents[i]->unmet_prereq_count == 0) {
                if ((action_list.contents[i]->food.source == Fry && has_fry) ||
                    (action_list.contents[i]->food.source == Mix && has_mix) ||
                    (action_list.contents[i]->food.source == Chop && has_chop) ||
                    (action_list.contents[i]->food.source == Boil && has_boil)
                        ) {
                    carry_count++;
                }
            }
        }

        while (carry_count != 0) {
            boolean deleted = false;
            int i = 0;

            while (i < action_list.length && !deleted) {
                if (((action_list.contents[i]->food.source == Fry && has_fry) ||
                     (action_list.contents[i]->food.source == Mix && has_mix) ||
                     (action_list.contents[i]->food.source == Chop && has_chop) ||
                     (action_list.contents[i]->food.source == Boil && has_boil)) &&
                    action_list.contents[i]->unmet_prereq_count == 0
                        ) {
                    insert_list_action(&action_group, action_list.contents[i]);

                    if (action_list.contents[i]->parent != NULL) {
                        action_list.contents[i]->parent->unmet_prereq_count--;
                    }

                    delete_list_action(&action_list, i);
                    carry_count--;
                    deleted = true;
                } else {
                    i++;
                }
            }
        }

        current_highest_priority--;
        insert_list_of_list_action(list, action_group);
    }
}

void create_action_priority(list_action_t *list, int target) {
    create_list_action(list);

    Tree t = lt_search_by_id(&list_tree_recipe, target);


    tranverse_tree(list, t, 0, NULL);

    if (AUTOBNMO_DEBUG) {
        printf("Recipe tree\n");
        display_tree(t);
        putchar('\n');
        printf("ACTION PRIORITY DEBUG\n");
        for (int i = 0; i < list->length; i++) {
            printf("Item idx %d with id %d\n", i, list->contents[i]->food.id);
            printf("Unmet prereq %d priority %d\n", list->contents[i]->unmet_prereq_count, list->contents[i]->priority);
            if (list->contents[i]->parent != NULL) {
                printf("Have parent with food id %d\n", list->contents[i]->parent->food.id);
            }
        }
    }
}

void tranverse_tree(list_action_t *list, Tree t, int depth, action_t *parent) {
    action_t *action = malloc(sizeof(action_t));
    action->food = t->food;
    action->parent = parent;
    action->priority = depth;
    action->unmet_prereq_count = 0;
    insert_list_action(list, action);

    for (int i = 0; i < t->children_count; i++) {
        Tree child = t->children[i];
        int count = food_count(simulator.inventory, child->food.id);

        if (count != 0) {
            tranverse_tree(list, child, depth + 1, action);
            action->unmet_prereq_count++;
        }
    }
}
