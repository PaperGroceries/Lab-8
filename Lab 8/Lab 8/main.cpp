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
    int arr_rating[5];
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
//        terrible_rating = 0;
//        bad_rating = 0;
//        ok_rating = 0;
//        good_rating = 0;
//        great_rating = 0;
        for(int i = 0; i < 5; i++)
        {
            arr_rating[i]=0;
        }
    };
    Movie (string new_name,string new_rating)
    {
        movie_name = new_name;
        MPAA_rating = new_rating;
//        terrible_rating = 0;
//        bad_rating = 0;
//        ok_rating = 0;
//        good_rating = 0;
//        great_rating = 0;
        for(int i = 0; i < 5; i++)
        {
            arr_rating[i]=0;
        }

    };
    
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

    //recieve number that corresposnds to rating and add a tick to the something_rating
//    if (rating == 1)
//    {
//        terrible_rating++;
//    }
//    else if (rating == 2)
//    {
//        bad_rating++;
//    }
//    else if(rating == 3)
//    {
//        ok_rating++;
//    }
//    else if( rating == 4)
//    {
//        good_rating++;
//    }
//    else if( rating == 5)
//    {
//        great_rating++;
//    }
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
    
    Movie movie1("Fight Club", "R");
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
    
    //std::cout << "Hello, World!\n";
    return 0;
}
