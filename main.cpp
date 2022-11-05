#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include "ellipse.h"
#include "helix.h"
#include "circle.h"

using namespace std;



int main()
{
//TASK 2
    srand(static_cast<unsigned int>(time(0)));
    vector <Circle*> FirstContainer;
    for(int i=0;i<100;i++)
    {
        cout <<i<<endl;
        int j=rand()%3;
        switch(j)
        {
            case 0:FirstContainer.push_back(new Circle(rand()%100,rand()%100,rand()%100));break;
            case 1:FirstContainer.push_back(new Ellipse(rand()%100,rand()%100,rand()%100,rand()%100));break;
            case 2:FirstContainer.push_back(new Helix(rand()%100,rand()%100,rand()%100,rand()%100,rand()%100));break;
            default:break;
        }

    }
//TASK 3
    for(unsigned int i=0;i<FirstContainer.size();i++)
        {
        cout << "Point x = "<<(*FirstContainer[i]).point(M_PI/4).x
                   << " y = "<<(*FirstContainer[i]).point(M_PI/4).y
                   << " z = "<<(*FirstContainer[i]).point(M_PI/4).z
                   <<"   Derivate = "
                   <<(*FirstContainer[i]).FDerivate(M_PI/4)
                   <<endl;
        }
 //TASK 4
    vector <Circle*> SecondContainer;
    for(unsigned int i=0;i<FirstContainer.size();i++)
    {
        if(!dynamic_cast<Ellipse*>(FirstContainer[i])&&!dynamic_cast<Helix*>(FirstContainer[i]))SecondContainer.push_back(FirstContainer[i]);
    }
    cout << "SecondContainer = "<<SecondContainer.size()<<endl;
 //TASK 5
    for (unsigned int i = 0; i < SecondContainer.size(); i++)
    {
      for (unsigned int j = 0; j < SecondContainer.size()-1; j++)
      {
       if((*SecondContainer[j]).getRadius()>(*SecondContainer[j+1]).getRadius())
       {

            Circle* x=SecondContainer[j];
            SecondContainer[j]=SecondContainer[j+1];
            SecondContainer[j+1]=x;
       }
      }
    }

    for(unsigned int i=0;i<SecondContainer.size();i++)cout<<" r = "<<(*SecondContainer[i]).getRadius()<<endl;
 //TASK 6,8(OpenMP parallel)
    double summRadii=0;
    #pragma omp parallel for shared(SecondContainer,summRadii)
    for(unsigned int i=0;i<SecondContainer.size();i++){
        summRadii+=(*SecondContainer[i]).getRadius();
    }

    cout<<" Summ of radii = "<<summRadii<<endl;
}
