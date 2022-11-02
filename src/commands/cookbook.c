#include "cookbook.h"


void cookbook() {
    printf("List Resep\n");
    printf("(aksi yang diperlukan - daftar bahan)\n");

    int counter = 1;

    for (int i = 0; i < list_tree_recipe.length; i++) {
        Tree t = list_tree_recipe.content[i];

        if (t->food.source != Buy) {
            printf("   %d. ", counter++);
            print_string(FOOD_NAME(t->food));
            putchar('\n');
            switch (FOOD_SOURCE(t->food)) {
                case (Buy):
                    break;
                case (Chop):
                    printf("      Chop - ");
                    break;
                case (Mix):
                    printf("      Mix - ");
                    break;
                case (Fry):
                    printf("      Fry - ");
                    break;
                case (Boil):
                    printf("      Boil - ");
                    break;
            }

            for (int j = 0; j < t->children_count; j++) {

                print_string(FOOD_NAME(t->children[j]->food));
                if (j != (t->children_count - 1)) {
                    printf(" - ");
                } else {
                    putchar('\n');
                };
            }
        }
    }
    
    printf("\nEnter command: ");
}
