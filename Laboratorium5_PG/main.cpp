#include <random>
#include <iostream>
#include <deque>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <string>
using namespace std;
pair <int,int> zad_5_1(vector <int> w){
    set<int> pom;
    int suma=0;
    pair <int,int> result;
    for(auto i: w){
        pair<set<int>::iterator,bool> res;
        res=pom.insert(i);
        if(!res.second){
            result.first=i;
        }
        else{
            suma+=i;
        }
    }
    result.second=suma;
    return result;

};
template <typename T>
void zad_5_2(set <T> zbior1,set <T> zbior2){
    set <T> sDiff;
    set_difference(zbior1.begin(),zbior1.end(),zbior2.begin(),zbior2.end(),insert_iterator<set <T>>(sDiff,sDiff.begin()));
    set_difference(zbior2.begin(),zbior2.end(),zbior1.begin(),zbior1.end(),insert_iterator<set <T>>(sDiff,sDiff.end()));
    for(auto i=sDiff.begin();i!=sDiff.end();i++){
        cout<<*i<<" ";
    }

    cout<<endl;
};
char zad_5_3(string napis1,string napis2){
    map<char,int>pom;
    for(auto i=0;i<napis1.length();i++){
        pom[napis1[i]]=1;
    }
     for(auto i=0;i<napis2.length();i++){
        pom[napis2[i]]+=1;
    }
    char zwracana;
    for(auto i=pom.begin();i!=pom.end();i++){
        if(i->second==1){
            zwracana=i->first;
        }
    }
    return zwracana;


};
int main()
{
     vector<int> vec = {15, 2, 3, 4,2, 5};
     auto wp=zad_5_1(vec);
     cout<<wp.first<<" "<<wp.second<<endl;
      set<int> a1 = {1, 2, 3, 4};
    set<int> b1 = {3, 4, 5, 6};
    zad_5_2<int>(a1,b1);
    cout<<endl;
    string a = "abcde";
    string b = "bdfeca"; // te same co pierwszy w innej kolejnosci plus "f"

    cout << a << ", " << b << ". Dodany znak: " << zad_5_3(a, b) << endl;

    a = "aanaa";
    b = "aaaa"; // dziala takze dla powtarzajacych sie
    cout << a << ", " << b << ". Dodany znak: " << zad_5_3(a, b) << endl;
    return 0;
}
