#include<iostream>
using namespace std;
class complex_no{
public:
    int real;
    int imaginary;
    complex_no()
    {
        real=0;
        imaginary=0;
    }
    friend istream &operator <<(istream, complex_no);
    friend ostream &operator >>(ostream, complex_no);
    complex_no operator +(complex_no);
    complex_no operator *(complex_no);
};
istream &operator>>( istream &input , complex_no &c){
    cout<<"\nEnter real part of complex number:  ";
    input>>c.real;
    cout<<"Imaginary part of complex number:   ";
    input>>c.imaginary;
    return input;
}
ostream &operator<<( ostream &output , complex_no &c){
    output<<"Complex no. is \t"<<c.real<<" + i"<<c.imaginary<<endl;
    return output;
}
complex_no complex_no::operator+(complex_no c1){

    complex_no temp;
    temp.real=real+c1.real;
    temp.imaginary=imaginary+c1.imaginary;
    return (temp);
}
complex_no complex_no::operator*(complex_no c1){
    complex_no temp;
    temp.real=(c1.real*real)-(c1.imaginary*imaginary);
    temp.imaginary=(c1.real*imaginary)+(c1.imaginary*real);
    return (temp);
}
int main(){
    complex_no c;
    int choice=0;
    complex_no c1,c2,c3,c4;
    cout<<"Default constructor value: "<<c.real<<"+i"<<c.imaginary<<endl;
    cout<<"\nPress 1 to enter two complex number \nPress 2 to display complex number \nPress 3 to add the number \nPress 4 to multiply\nPress 5 to exit"<<endl;

    do{
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cin>>c1;
                cin>>c2;
                break;
            case 2:
                cout<<c1;
                cout<<c2;
                break;
            case 3:
                c3=c1+c2;
                cout<<c3;
                break;
            case 4:
                c4=c1*c2;
                cout<<c4;
                break;
            case 5:
                cout<<"Exitting...";
                break;
            default:
                cout<<"wrong choice";
        }}while(choice<5);
    return 0;
}
