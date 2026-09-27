#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BOOK
{
protected:
string author;
string name;
double price;
public:
BOOK(string n,string a, double p):author(a),name(n),price(p){}
virtual void display (){
 cout << "name=" <<name<< endl;
 cout << "price=" <<price<< endl;
cout << "author=" <<author<< endl;
}
BOOK(const BOOK&b){
name=b.name;
price=b.price;
author=b.author;


}
virtual ~BOOK(){}
 };
 class paperBook: public BOOK{
   int pagenumber;
   public:
   paperBook(string n,string a, double p,int page):BOOK(n,a,p),pagenumber(page){}
    void display () override {
    cout << "paper book" << endl;
 BOOK::display();
cout << "pagenumber=" <<pagenumber<< endl;
cout << "===================" << endl;

}
 
 };
 class Ebook: public BOOK{
   int size;
   public:
   Ebook(string n,string a, double p,int s):BOOK(n,a,p),size(s){}
    void display () override {
    cout << "Ebook" << endl;
 BOOK::display();
cout << "size=" <<size<<"MB" <<endl;
cout << "===================" << endl;

}
 
 };
 
 class library {
 public:
  vector<BOOK*>book;
  void addbook(BOOK*b) 
  {
  book.push_back(b);
  }
 void showtotal(){
   cout << "total books="<<book.size() << endl;
  }
  
 void showallbook() const{
    for (size_t i = 0; i < book.size(); i++) {
        book[i]->display();
    }
}

  
 ~library(){
  for(size_t i=0;i<book.size();i++){
   delete book[i];
  }
  book.clear();
 }
 
 
 
 };
 int main(){
 Ebook *b1=new Ebook("yara","Yuri",50000,45);
  Ebook*b2=new Ebook("pp","Yuri",77,15);
 paperBook *b3=new paperBook("hhh","rrr",9099,358);
 paperBook* b4 = new paperBook(*b3); 
 library l;
 l.addbook(b1);
 l.addbook(b2);
 l.addbook(b3);
 l.addbook(b4);
 l.showallbook();
 l.showtotal();
 
  
 
 
 return 0;
 }
  
  
  

    