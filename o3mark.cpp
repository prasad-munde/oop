#include <iostream>
#include <string>

using namespace std;

//base class
class Publication
{
protected:
    string title;
    float price;

public:
    Publication(const string& t = "", float p = 0.0f) : title(t), price(p)   //constructor
    {
    }

    virtual void display() const
    {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }

    virtual ~Publication() = default;      //destructor
};

//generalised class
class Book : public Publication
{
private:
    int pageCount;

public:
    Book(const string& t = "", float p = 0.0f, int pc = 0) : Publication(t, p), pageCount(pc)  //constructor
    {
    }

    void display() const override
    {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

//generalised class
class Tape : public Publication
{
private:
    float playingTime;

public:
    Tape(const string& t = "", float p = 0.0f, float pt = 0.0f) : Publication(t, p), playingTime(pt)
    {
    }

    void display() const override
    {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

//main function
int main()
{
    string title;
    float price;
    int pageCount;
    float playingTime;

    // Input for Book
    cout << "Enter details for Book:" << endl;
    cout << "Title: ";
    getline(cin, title);
    cout << "Price (in dollars): ";
    cin >> price;
    cout << "Page Count: ";
    cin >> pageCount;

    Book book(title, price, pageCount);
    cin.ignore();
    // Input for Tape
    cout << "\nEnter details for Tape:" << endl;
    cout << "Title: ";
    getline(cin, title);
    cout << "Price (in dollars): ";
    cin >> price;
    cout << "Playing Time (in minutes): ";
    cin >> playingTime;
    
    Tape tape(title, price, playingTime);

    // Display details
    cout << "\nBook Details:" << endl;
    book.display();

    cout << "\nTape Details:" << endl;
    tape.display();

    return 0;
}
