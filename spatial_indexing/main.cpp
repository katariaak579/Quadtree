#include <iostream>
#include "tree.cpp"

using namespace std;

int main() {
    cout << "Please Enter the maximum x and y coordinate of square/rectangle you want to construct in the format x y where x and y are the maximum x, y coordinates in the figure: ";
    int x, y;
    scanf("%d%d", &x, &y);
    int data_point;
    int a, b;
    Quad tree(coordinates(0, 0), coordinates(x, y));
    Node nodes[100000];
    int count=0;
    int input;
    do {
        printf("\n*****MENU*****");
        printf("\n1. Insert Element & Data");
        printf("\n2. Search an Element Data Point");
        printf("\n3. Check if element exist in Quad Tree & Get its address");
        printf("\n4. Quit");
        printf("\nEnter your choice: ");

        scanf("%d", &input);
        if (input == 1) {
            printf("\nEnter the element coordinates to be inserted in form x,y: ");
            scanf("%d%d", &a, &b);
            if (a > x || b > y) {
                cout << endl << "Point Outside figure. Can't Insert";
                continue;
            }
            printf("\nEnter the data associated with the coordinates: ");
            scanf("%d", &data_point);
            nodes[count].loc=coordinates(a,b);
            nodes[count].data=data_point;
            tree.insert(&nodes[count++]);
            continue;
        }
        if (input == 2) {
            printf("\nEnter the element to be searched in form x y: ");
            scanf("%d%d", &a, &b);
            if (tree.search(coordinates(a, b)) == nullptr)
                cout << "\nPoint does not exist in quad tree";
            else
                cout <<"The data associated with entered coordinates is->" << tree.search(coordinates(a, b))->data;
            continue;
        }
        if (input == 3) {
            printf("\nEnter the element to be checked in form x y:");
            scanf("%d%d", &a, &b);
            if (tree.search(coordinates(a, b)) == nullptr)
                cout << "\nPoint does not exist in quad tree";
            else
            {
                cout << "\nPoint exists in Quad Tree";
                printf("Element exists at: "); cout<<tree.search(coordinates(a, b));
            }
            continue;
        }
        if (input == 4) {
            return 0;
        } else
            printf("\nNot a valid option\n");
    } while (input != 5);
}
