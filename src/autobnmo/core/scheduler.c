#include "scheduler.h"

// todo: hitung total waktu setiap aksi pada grup
// lakukan dijkstra algorithm

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
                if ((action_list.contents[i]->food.source == Fry && has_fry) ||
                    (action_list.contents[i]->food.source == Mix && has_mix) ||
                    (action_list.contents[i]->food.source == Chop && has_chop) ||
                    (action_list.contents[i]->food.source == Boil && has_boil)
                        ) {
                    insert_list_action(&action_group, action_list.contents[i]);

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

        if (count == 0) {
            tranverse_tree(list, child, depth + 1, action);
            action->unmet_prereq_count++;
        }
    }
}
