#include <bits\stdc++.h>

#include "prufer_code.h"
#include "GraphColor.h"
#include "DoNuoc.h"
#include "lienthongmanh.h"
#include "Connected_Component_Graph.h"
#include "Shortest_Path_Graph.h"
#include "SCC_Digraph.h"
#include "Shortest_Path_Digraph.h"
#include "Path_Planning.h"


using namespace std;

int main () {
    cout << "MENU\n"
        << "1. Tim ma PruferCode\n"
        << "2. To mau do thi\n"
        << "3. Giai bai toan do nuoc\n"
        << "4. Dem so thanh phan lien thong manh cua do thi\n"
        << "5. Dem so thanh phan lien thong cua do thi VO HUONG\n" 
            << "duoc tao boi cac tu trong tep sgb_words\n"
        << "6. Tim duong di ngan nhat tu dinh u toi dinh v tren do thi VO HUONG tu sgb_words\n"
        << "7. Dem so thanh phan lien thong manh cua do thi CO HUONG\n"
            << "duoc tao boi cac tu trong tep sgb_words\n"
            << "In ra cac tu cung thanh phan lien thong voi tu duoc nhap tu ban phim\n"
        << "8. Tim duong di ngan nhat tu dinh u toi dinh v tren do thi CO HUONG tu sgb_words\n"
        << "9. Tim duong cho robot\n";

    int choice;
    cout << "Nhap chuc nang can dung: "; cin >> choice;
    switch (choice)
    {
        case 1: Display_Purfercode(); break;
        case 2: Display_Tomau(); break;
        case 3: Display_Donuoc(); break;
        case 4: Display_LienThongManh(); break;
        case 5: Display_CCGraph(); break;
        case 6:  Display_SPG(); break;
        case 7: Display_SCC_Digraph(); break;
        case 8: Display_SP_Digraph(); break;
        case 9: Display_PathPlanning(); break;
        default:
            cout << "Chuc nang khong ton tai\n";
            break;
    }  
    
    
    return 0;
}