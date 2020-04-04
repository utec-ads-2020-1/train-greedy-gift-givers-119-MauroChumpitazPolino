#include <iostream>
using namespace std;

int name_comparator(string n_in, string nms[]);

int main (){

    unsigned short int n_people;
    cin >> n_people;

    string names[n_people];
    string name_in;
    int avg_money[n_people] ={};
    int given_money;
    int iter_num;
    int pos;

    for (int i = 0; i < n_people; i++){
        cin >> names[i];
    }
    
    for (int j = 0; j < n_people; j++){
        cin >> name_in;
        pos = name_comparator(name_in, names);

        cin >> given_money;

        if (given_money > 0){
            avg_money[pos] = avg_money[pos] -given_money;

            cin >> iter_num;
            iter_num = (iter_num == 0)? 1 : iter_num;

            given_money = given_money / iter_num;
            for(int i = 0; i < iter_num; i++){
                cin >> name_in;
                pos = name_comparator(name_in, names);
                avg_money[pos] = avg_money[pos] + given_money;
            }
        }
        else{
            cin.ignore(256, '\n');
        }
        
    }

    for (int i = 0; i < n_people; i++){
        cout << names[i] << " " << avg_money[i] << endl;
    }
           

    return 0;
}

int name_comparator(string n_in, string nms[]){
    int i = 0;
    bool ok_pos = false;

    while(ok_pos == false){
        if(n_in.compare(nms[i]) == 0){
            ok_pos = true;
        }
        else{
            i++;
        }
    }
    return i;
}