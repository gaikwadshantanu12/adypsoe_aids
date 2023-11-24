#include<conio.h>
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class drawpattern {
    private:
        float dx,dy,i ,length;
        float count;
    public:
        int x1,y1,x2,y2;
        int xmid,ymid;
        void getdata();
        void ddaline(int x1,int x2,int y1, int y2);
        int xc,yc,r;
        void bdrawcircle(int xc,int yc,int r);
};

void drawpattern::getdata() {
    cout<<"Enter x1 : ";
    cin>>x1;
    cout<<"Enter y1 : ";
    cin>>y1;
    cout<<"Enter x2 : ";
    cin>>x2;
    cout<<"Enter y2 : ";
    cin>>y2;
}

void drawpattern::ddaline(int x1, int x2, int y1, int y2) {
    float x,y;
    dx = (x2-x1);
    dy = (y2-y1);
    if(abs(dx)>=abs(dy)) 
        length = abs(dx);
    else 
        length = abs(dy);
    dx = dx/length;
    dy = dy/length;
    x=x1;
    y=y1;
    i=1;
    while(i<=length) {
        x = x + dx;
        y = y + dy;
        putpixel(x,y,15);
        i++;
    }
}

void drawpattern::bdrawcircle(int xc,int yc,int r) {
    int x,y,d;
    x=0;
    y=r;
    putpixel(xc+x,yc-y,15);
    d=3-2*r;
    do {
        putpixel(xc+x,yc+y,15);
        putpixel(xc-x,yc-y,15);
        putpixel(xc+x,yc-y,15);
        putpixel(xc-x,yc+y,15);
        putpixel(xc+y,yc-x,15);
        putpixel(xc-y,yc-x,15);
        putpixel(xc+y,yc+x,15);
        putpixel(xc-y,yc+x,15);
        if(d<0) {
            y=y;
            d=d+4*x+6;
        }
        else {
            d=d+4*(x-y)+10;
            y=y-1;
        }
        x=x+1;
    } while(x<=y);
}

int main() {
    int gdriver= DETECT, gmode;
    initgraph(&gdriver,&gmode,"c://Turboc3//BGI");
    cleardevice();
    drawpattern d;
    d.getdata();
    d.ddaline(d.x1,d.y1,d.x2,d.y1);// (x1,y1) and (x2,y1)
    d.ddaline(d.x2,d.y1,d.x2,d.y2);
    d.ddaline(d.x2,d.y2,d.x1,d.y2);
    d.ddaline(d.x1,d.y2,d.x1,d.y1);
    d.xmid=abs((d.x1+d.x2))/2;
    d.ymid=abs((d.y1+d.y2))/2;
    d.ddaline(d.xmid,d.y1,d.x2,d.ymid);// (x1,y1) and (x2,y1)
    d.ddaline(d.x2,d.ymid,d.xmid,d.y2);
    d.ddaline(d.xmid,d.y2,d.x1,d.ymid);
    d.ddaline(d.x1,d.ymid,d.xmid,d.y1);
    float rad,cal,sidex,sidey;
    sidex=abs(d.x2-d.x1);
    sidey=abs(d.y2-d.y1);
    cal=pow(sidex,2)+pow(sidey,2);
    cal=2*sqrt(cal);
    rad=(sidex*sidey)/cal;
    cout << "Side X : " << sidex <<"\tSide Y : "<<sidey;
    cout << "\nRadius : " << rad;
    d.bdrawcircle(d.xmid,d.ymid,rad);
    getch();
    closegraph();
    // getch();
    return 0;
}
