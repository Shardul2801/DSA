#include"bits/stdc++.h"
using namespace std;

float areaOfTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
float distanceOfSide(int x1,int y1,int x2,int y2){
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}

bool isDegenerative(int x1,int y1,int x2,int y2,int x3, int y3){
    int ab = distanceOfSide(x1,x2,y1,y2);
    int bc = distanceOfSide(x2,y2,x3,y3);
    int ac = distanceOfSide(x1,y1,x3,y3);

    if(ab + ac > bc && ab + bc > ac && bc + ac > ab){
        return 1;
    }
}

int check(int px,int py,int qx,int qy, int x1, int y1, int x2, int y2, int x3, int y3){
    int A1 = areaOfTriangle( px,py,x1,y1,x2,y2);
    int A2 = areaOfTriangle(px,py,x1,y1,x3,y3);
    int A3 = areaOfTriangle(px,py,x2,y2,x3,y3);
    int A = areaOfTriangle(x1,y1,x2,y2,x3,y3);

    int a1 = areaOfTriangle( qx,qy,x1,y1,x2,y2);
    int a2 = areaOfTriangle(qx,qy,x1,y1,x3,y3);
    int a3 = areaOfTriangle(qx,qy,x2,y2,x3,y3);    


    if(!isDegenerative(x1,y1,x2,y2,x3,y3)){
        return 0;
    }
    if(A1 + A2 + A3 == A && a1 + a2 + a3 != A){
        return 1;
    }
    else if(a1 + a2 + a3 == A && A1 + A2 + A3 != A){
        return 2;
    }
    else if(A1 + A2 + A3 == A && a1 + a2 + a3 == A){
        return 3;
    }
    else{
        return 4;
    
    }

}


int main(){

    int x1,x2,x3,y1,y2,y3,px,py,qx,qy;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>px>>py>>qx>>qy;
    cout<<check(px,py,qx,qy,x1,y1,x2,y2,x3,y3);
   

    return 0;
}
