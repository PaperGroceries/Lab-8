//
//  main.cpp
//  Lab 8
//
//  Created by Aim Kim on 2022-07-25.
//
#include <iostream>
#include <string>

using namespace std;
//all data memn,ber private
//change

class Movie
{
    string movie_name;
    string MPAA_rating;
    int *arr_rating;
    int terrible_rating;
    int bad_rating;
    int ok_rating;
    int good_rating;
    int great_rating;
public:
    int addRating(int rating);
    double getAverage();
    string getName();
    string getMPAA();
    void setMPAA(string newMPAA);
    void setName(string newName);
    
public:
    Movie ()
    {
        movie_name = "Empty";
        MPAA_rating = "Empty";

        arr_rating = new int[5];
        for(int i = 0; i < 5; i++)
        {
            arr_rating[i]=0;
        }
    };
    
    Movie(Movie &y){
          // deep copy
          this->arr_rating = new int[5];
          for(int i = 0; i < 5; i++){
              this->arr_rating[i] = y.arr_rating[i];
          }
      }
    
    void operator=(Movie x){ // x(movie2)
           // deep copy
           for(int i = 0; i < 5; i++){
               this->arr_rating[i] = x.arr_rating[i];
           }
       }
    Movie (string new_name,string new_rating)
    {
        movie_name = new_name;
        MPAA_rating = new_rating;

        arr_rating = new int[5];
        for(int i = 0; i < 5; i++)
        {
            arr_rating[i]=0;
        }

    };
    ~Movie()
    {
        delete []arr_rating;
    }
    
};
string Movie :: getName()
{
    return movie_name;
};

string Movie::getMPAA()
{
    return MPAA_rating;
};
void Movie::setMPAA( string newMPAA)
{
    MPAA_rating = newMPAA;
}
void Movie::setName(string newName)
{
    movie_name = newName;
}
int Movie::addRating(int rating)
{
 
    for (int i = 0;i < 5;i++)
    {
        if (i == (rating - 1))
        {
            arr_rating[i]++;
        }
    }
    return 0;
}
double Movie::getAverage()
{
    int sum = 0;
    int divident = 0;
    for (int  i = 0; i < 5; i++)
    {
        sum += arr_rating[i] * (i + 1);
        divident += arr_rating[i];
    }
    return sum/(divident * 1.0);
//    return (terrible_rating * 1
//             + bad_rating * 2
//             + ok_rating * 3
//             + good_rating * 4
//             + great_rating * 5)
//    /
//    (terrible_rating + bad_rating + ok_rating + good_rating + great_rating * 1.0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Movie arr[4];
    Movie **arra;
    arra = new Movie*[4];
    arra[0] = new Movie("Rio", "E");
    arra[1] = new Movie("Fight Club", "E");
    arra[2] = new Movie("Minions", "E");
    arra[3] = new Movie("Machete", "E");
    
    for (int i =0 ; i < 4;i++)
    {
        arra[i]->addRating(1);
        arra[i]->addRating(1);         // Terrible
        arra[i]->addRating(3);         // OK
        arra[i]->addRating(3);         // OK
        arra[i]->addRating(5);
        
    }
    
    for (int k = 0; k <4; k++)
    {
       cout << arra[k]->getName() << endl;
       cout << arra[k]->getMPAA() << endl;
       cout << arra[k]->getAverage() << endl;
    }
//    arr[0] = Movie("Rio", "E");
//    arr[1] = Movie("Fight Club","R");
//    arr[0] = Movie("Minions", "PG-13");
//    arr[1] = Movie("Machete","E");
//    for (int i =0 ; i < 4;i++)
//    {
//        arr[i].addRating(1);
//        arr[i].addRating(1);         // Terrible
//        arr[i].addRating(3);         // OK
//        arr[i].addRating(3);         // OK
//        arr[i].addRating(5);
//
//    }
//    for (int k = 0; k <4; k++)
//    {
//       cout << arr[k].getName() << endl;
//       cout << arr[k].getMPAA() << endl;
//       cout << arr[k].getAverage() << endl;
//    }
    
    cout << arra[0]->getName() << endl;
//    cout << arra[k].getMPAA() << endl;
//    cout << arra[k].getAverage() << endl;
    
    Movie movie1("Time-loop", "R");
    movie1.addRating(5);         // Great
    movie1.addRating(1);         // Terrible
    movie1.addRating(3);         // OK
    movie1.addRating(3);         // OK
    movie1.addRating(5);         // Great
    cout << movie1.getName()<< endl;            // "Fight Club",
    cout << movie1.getMPAA()<< endl;            //  "R";
    cout << movie1.getAverage() << endl; // 3.4

    Movie movie2;
    movie2.setName("The GodFather");
    movie2.setMPAA("PG-13");
    movie2.addRating(1);         // Terrible
    movie2.addRating(3);         // Terrible
    movie2.addRating(5);         // OK
    movie2.addRating(5);         // OK
    movie2.addRating(5);         // Great
    cout << movie2.getName()<< endl;            // "The GodFather"
    cout << movie2.getMPAA()<< endl;            //"PG-13"
    cout << movie2.getAverage()<< endl; // 3.8
    
//    delete [0]arra;
//    delete [1]arra;
//    delete [2]arra;
//    delete [3]arra;
    //std::cout << "Hello, World!\n";
//} while (selection != 4);
//
//     delete arr[0];
//
//     delete arr[1];
//
//     delete arr[2];
//
//     delete arr[3];
//
//     delete arr;
//     return 223;
// }
//    return 0;
}
