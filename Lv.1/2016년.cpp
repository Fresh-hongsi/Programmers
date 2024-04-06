#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    
    int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string result = "";
    
    int totalDay = 0;
    for(int i=0;i<a-1;i++){
        totalDay+=months[i];
    }
    totalDay+=b-1;
    
    if(totalDay%7==0){
        result="FRI";
    }else if(totalDay%7==1){
        result="SAT";
    }else if(totalDay%7==2){
        result="SUN";
    }else if(totalDay%7==3){
        result="MON";
    }else if(totalDay%7==4){
        result="TUE";
    }else if(totalDay%7==5){
        result="WED";
    }else if(totalDay%7==6){
        result="THU";
    }
    
    
    return result;
}
