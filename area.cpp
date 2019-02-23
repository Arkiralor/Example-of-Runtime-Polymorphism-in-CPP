#include<iostream>

using namespace std;

class area
{
	public:	
		float radius, base, height, pi=3.1416, length, width;
		virtual void area1()=0;
};

class areacircle: public area
{
	public:
		void area1()
		{
			cout<<"\nEnter the radius :";
			cin>>radius;
			float area=pi*radius*radius;
			cout<<"\nThe area of the given circle is "<<area<<" sq-units. \n";
		}
};

class areatriangle: public area
{
	public:
		void area1()
		{
			cout<<"\nEnter the base and height. \n";
			cin>>base;
			cin>>height;
			float area=0.5*base*height;
			cout<<"\nThe area of the given triangle is "<<area<<" sq-units. \n";
		}
};

class arearectangle: public area
{
	public:
		void area1()
		{
			cout<<"\nEnter the length and width. \n";
			cin>>length;
			cin>>width;
			float area=length*width;
			cout<<"\nThe area of the given rectangle is "<<area<<" sq-units. \n";
		}
};


		
int main()
{
	area *o1, *o2, *o3;
	areacircle oc;
	areatriangle ot;
	arearectangle orec;
	o1=&oc;
	o2=&ot;
	o3=&orec;
	int choice;
	cout<<"\n################################################";
	cout<<"\n##################### MENU #####################";
	cout<<"\n################################################";
	cout<<"\nSelect the shape: \n1. Circle \n2. Triangle \n3. Rectangle \n4. All of the above. \n";
	cout<<"\n################################################\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			o1->area1();
			break;
		case 2:
			o2->area1();
			break;
		case 3:
			o3->area1();
			break;
		case 4:
			o1->area1();
			o2->area1();
			o3->area1();
			
			break;
		default:
			cout<<"\nInvalid selection, aborting process. \n";
	}
	return 0;
}