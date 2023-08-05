// C++ implementation of Dynamic Array
#include <iostream>
#include<stdio.h>
using namespace std;

//template <class T> // this is a template class. It's helpful since we don't know what's the data of of the DAL that the user wants (int, float or some user-def Data type
class DynamicArray {
private:
    int * d_array; //a pointer that we'll use to store whatever data we need
    int max_size; //to store the current array's max possible size (it doubles, remember?)
    int length; //to store array's current length
public:
    DynamicArray() //a constructor function, it's called whenever a object of this class is created

    {
        // initially allocate a single memory block
        max_size = 2;
        d_array = new int[max_size];   // like int * a = new int [10], this is static
        length = 0;
    }

    // insert a new item to the end of the d_array
    void add(int item) {
        if (isFull()) {
            // create temporary array with double the size of the previous array
            max_size = 2 * max_size;
            int * temp_d_array = new int[max_size];
            cout<<"\nDAL Limit reached, new array created, values copied\n"<<endl;
            // move all the elements to the temporary d_array
            for (int i = 0; i < length; i++) {
                temp_d_array[i] = d_array[i];
            }

            // delete the old d_array
            delete [] d_array;

            // assign temp d_array's ptr to d_array
            d_array = temp_d_array;

           // delete [] temp_d_array;
        }

        // add the new item at the end of the d_array
        //the following portion is out of the if condition, since this will happen for both the cases
        //the if portion contains only the new array declaration and copying portion
        d_array[length] = item;

        length++;
    }

    void printd_array() {
        for (int i = 0; i < length; i++) {
            cout<<d_array[i]<<' ';
        }
        cout<<endl;
    }

    // check if the d_array is full
    bool isFull() {
        return length == max_size;

    }
    void Delete(int x)
    {
        for(int i=x-1;i<length-1;i++)
        {
            d_array[i]=d_array[i+1];
        }
        length--;
    }
    void Insert(int p, int x)
    {
        for(int i=length-1;i>=p-1;i--)
        {
            d_array[i+1]=d_array[i];
        }
        d_array[p-1]=x;
        length++;
    }
     void deleteEq(int a)
    {
        bool occured=false;
        for(int i=0;i<length;i++)
        {
            if(d_array[i]==a)
            {
                for(int j=i;j<length;j++)
                {
                    d_array[j]=d_array[j+1];
                }
                length--;
                i--;
                occured=true;
            }
        }
        if(!occured)
        {
            cout<<"ITEM OCCURED ONLY ONCE\n";
        }
    }
    void Replace(int x,int r)
    {
        int flag;
        for(int i=0;i<length;i++)
        {
            flag=0;
            if(d_array[i]==x)
            {
                for(int j=i;j<length;j++)
                {
                    if(d_array[i]==d_array[j])
                    {
                        d_array[j]=r;
                        flag=1;
                    }
                }
            }
            if(flag==0)
            {
                cout<<"No occurrence of "<<x<<" was found.\nNo Items were replaced ";
                break;
            }
        }
        if(flag)
        {
            cout<<"The current array is:\n";
                for(int i=0;i<length;i++)
                {
                    cout<<d_array[i]<<" ";
                }
        }
    }
    int FactLarge()
    {
        int max=d_array[0],ans=1;
        for(int i=0;i<length;i++)
        {
            if(d_array[i]>max)
            {
                max=d_array[i];
            }
        }
        for(int j=max;j!=0;j--)
        {
            ans*=j;
        }
        cout<<"Factorial Of The Largest Element is ="<<ans<<endl;
    }
    ~DynamicArray() //a destructor function, deallocates memory when the program closes/object is no longer needed
    {
        delete [] d_array;
    }


};

int main() {

    DynamicArray dal;

    int a, choice;
    printf("\t\tDynamic Array d_array Implementation using Template Class.\n");


   while (1)
{


    printf("\n1.Add an element\n2.See current Elements");
    printf("\n3.Delete element from a particular position\n4.Insert at a particular position\n5.Delete matching values\n6.Replace matching values\n7.Factorial of the largest number.\n8.Exit.\nPress any other key to terminate the program. ");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);



    if(choice==1)
    {
        printf("\nEnter a num to add: ");
        scanf("%d", &a);
        dal.add(a);

        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }

    else if (choice==2)
    {
        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }

     else if (choice==3)
    {
        int x;
       //do by yourself
       //Let the user delete the value from a particular position in the DAL.
       cout<<"Enter the position to delete: ";
       cin>>x;
       dal.Delete(x);
       cout<<"\nThe current dynamic array is ";
       dal.printd_array();
    }

    else if (choice==4)
    {
       //do by yourself
       //Let the user insert a value into a particular position in the DAL.
       int pos,ele;
       cout<<"Enter position to insert: ";
       cin>>pos;
       cout<<"\nEnter value to insert: ";
       cin>>ele;
       dal.Insert(pos,ele);
       cout<<"\n";

       dal.printd_array();
    }
    else if (choice==5)
    {
       //do by yourself
       //Delete ALL matching values. Resize the Dynamic array as per the algorithm shown in class
       //think when it�ll be resized carefully
        int x;
        cout<<"Enter the value to delete: ";
        cin>>x;
        dal.deleteEq(x);
        cout<<"\n";
        
    }
    else if (choice==6)
    {
       //do by yourself
       //Replace ALL matching values.

       //There may be two cases as shown in the sample input-output.
        int x,r;
        cout<<"Enter the value to replace: ";
        cin>>x;
        cout<<"Enter the value to replace by: ";
        cin>>r;
        dal.Replace(x,r);
    }
    else if (choice==7)
    {
       //do by yourself
       /*A unique function that you think can be beneficial for DALs.
        Write appropriate comments on top of your function. */
        dal.FactLarge();
    }

    else
    {
        printf("\n\t\tProgram Terminated\n\n");
        break;
    }


}



    return 0;
}
