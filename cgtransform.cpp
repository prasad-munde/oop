#include<iostream>
#include<cmath>
#include<graphics.h>
#define M 10

using namespace std;

class graph
{
private:
    int A[M][M],ans[M][M],trans[3][3],color,n;
    float rotate[2][2],scale[2][2];
public:
    graph();
    void drawline(float,float,float,float);
    void polynomial();
    int sign(float);
    void Show_poly();
    void translation();
    void Scaling();
    void Rotation();
    void Display();
    void try_i();
};

graph::graph()
{
    color=RED;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                trans[i][j]=1;

            else
                trans[i][j]=0;
        }

    }

    scale[0][0]=1;
    scale[0][1]=0;
    scale[1][0]=0;
    scale[1][1]=1;
}

void graph::try_i()
{
    int t;
    cout<<"Enter rotation angle value in degree : ";
    cin>>t;
}
void graph::drawline(float x1,float y1,float x2,float y2)
{
    int dx,dy,length,x,y;
    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>=dy)
        length=dx;
    else length=dy;

    dx=(x2-x1)/length;
    dy=(y2-y1)/length;
    x=x1+0.5*sign(dx);
    y=y1+0.5*sign(dy);

    int i=0;
    while(i<=length)
    {
        x=x+dx;
        y=y+dy;
        putpixel(x,y,color);
        i=i+1;
    }
}

int graph::sign(float a)
{
    if(a<0)
        return -1;
    else if(a==0)
        return 0;
    else
        return 1;
}

void graph::polynomial()
{
    cout<<"Enter number of vertex: ";
    cin>>n;

    cout<<"Enter vertex coordinate serially."<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter X coordinate of point "<<i+1<<": ";
        cin>>A[i][0];
        cout<<"Enter Y coordinate of point "<<i+1<<": ";
        cin>>A[i][1], cout<<endl;
        A[i][2]=1;
    }
}

void graph::Show_poly()
{
    color=RED;
    for(int i=0;i<n-1;i++)
    {
        line(A[i][0],A[i][1],A[i+1][0],A[i+1][1]);
    }
    line(A[0][0],A[0][1],A[n-1][0],A[n-1][1]);
}

void graph::translation()
{
    int tx,ty;
    color=GREEN;
    cout<<"Enter translation value tx: ", cin>>tx;
    cout<<"Enter translation value ty: ", cin>>ty, cout<<endl;
    trans[2][0]=tx;
    trans[2][1]=ty;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            ans[i][j]=A[i][0]*trans[0][j]+A[i][1]*trans[1][j]+A[i][2]*trans[2][j];
        }
    }

    Display();
}

void graph::Scaling()
{
    int sx,sy;
    color=YELLOW;
    cout<<"Enter Scaling value sx: ", cin>>sx;
    cout<<"Enter Scaling value sy: ", cin>>sy, cout<<endl;
    scale[0][0]=sx;
    scale[1][1]=sy;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans[i][j]= A[i][0] * scale[0][j] + A[i][1] * scale[1][j];
        }
    }
    Display();
}

void graph::Rotation()
{
    color=RED;
    int t;
    cout<<"Enter rotation angle (in degree) : ", cin>>t, cout<<endl;
    rotate[0][0]=cos(t * 3.14 / 180);
    rotate[0][1]= -1 * sin(t * 3.14 / 180);
    rotate[1][0]=sin(t * 3.14 / 180);
    rotate[1][1]=cos(t * 3.14 / 180);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans[i][j]= A[i][0] * rotate[0][j] + A[i][1] * rotate[1][j];
        }
    }

    Display();
}

void graph::Display()
{
    for(int i=0;i<n-1;i++)
    {
        setcolor(color);
        line(ans[i][0],ans[i][1],ans[i+1][0],ans[i+1][1]);
    }

    line(ans[0][0],ans[0][1],ans[n-1][0],ans[n-1][1]);
}

int main()
{
    graph obj;
    int gd=DETECT,gm=DETECT;
    initgraph(&gd, &gm, NULL);
    int t,ch;

    while(1)
    {
        cout<<"1. Create coordinate\n2. Show polygon\n3. Translation\n4. Scaling\n5. Rotation\n6. Exit\n"<<"Enter choice: ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
                obj.polynomial();
                break;

            case 2:
                obj.Show_poly();
                break;

            case 3:
                obj.translation();
                break;

            case 4:
                obj.Scaling();
                break;

            case 5:
                obj.Rotation();
                break;

            case 6:
                cout<<"Exiting...";
                exit(0);

            default:
                cout<<"\nWrong Choice, Try again...";
        }
    }
}
