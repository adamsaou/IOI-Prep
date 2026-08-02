#include <bits/stdc++.h>

using namespace std;

struct Student{
    string name;
    int grade;
    int age;
};

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin>>n;

    vector <Student> s(n);

    for(int i = 0; i<n;i++){
        cin >> s[i].name >> s[i].grade >> s[i].age;
    }

    sort(s.begin(), s.end(), [](const Student& a, const Student& b){
        if (a.grade != b.grade){
            return a.grade > b.grade;
        }
        if (a.age != b.age){
            return a.age < b.age;
        }
        return a.name < b.name;
    });

    for(int i = 0; i<n;i++){
        cout << s[i].name <<" "<< s[i].grade <<" "<< s[i].age << "\n";
    }
    
    return 0;
}