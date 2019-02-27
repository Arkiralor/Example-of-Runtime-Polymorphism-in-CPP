//Sample program to test runtime polymorphism parameters using a basic area claculator.

#include<iostream>

using namespace std;

void switch1(int x); //initialisation of switch-case function named, "switch1".

class shape //declaration of base class.
{
	public:
		float r, b, h, l, w, pi=3.1416; //all possible atrributes in program.
		virtual void area1()=0; //initial pure virtual function to find the area.
		virtual void entry1()=0; //initial pure virtual function to take attributes from uer-input.
};

class circle: public shape //class circle derived from class shape.
{
	public:
		void area1(); //function to calculate the area of the circle.
		void entry1(); //function to enter attribute(s) of circle i.e, the radius.
};

class triangle: public shape //class triangle derived from class shape.
{
	public:
		void area1(); //function to calculate the area of the triangle.
		void entry1(); //function to enter attributes of triangle i.e, the base and height.
};

class rectangle: public shape
{
	public:
		void area1(); //function to calculate the area of the rectangle.
		void entry1(); //function to enter the attributes of the rectangle i.e, the lenght and width.

};

int main()
{
	int choice;
	cout<<"\n--------------------\n";
	cout<<"\n--------MENU--------\n";
	cout<<"\nPlease select the shape. \n1. Circle \n2. Triangle \n3. Rectangle \n4. All shapes. \n"; //basic menu.
	cout<<"\n--------------------\n";
	cin>>choice; //actual argument for switch-case function.

	switch1(choice); //argument passed to switch-case function.
	

	return 0; //come on! I seriously should not need to explain this of all things!
}

			
void circle::entry1() //function definition of entry1 for class circle.
{
	cout<<"\nEnter the radius. \n";
	cin>>r; //console-input for the radius.
}
void circle::area1() //function definition of area1 for class circle.
{
	float area=pi*r*r; //simple expression based on the formula for the area of a circle.
	cout<<"\nThe area of the given circle is "<<area<<" sq-units. \n";
}
void triangle::entry1() //function definition of entry1 for class triangle.
{
	cout<<"\nEnter the base and height, respectively. \n";
	cin>>b>>h; //console-input for base and height.
}
void triangle::area1() //function definition of area1 for class triangle.
{
	float area=0.5*b*h; //simple expression based on the formula for the area of a triangle.
	cout<<"\nThe area of the given triangle is "<<area<<" sq-units. \n";
}
void rectangle::entry1() //function definition of entry1 for class rectangle.
{
	cout<<"\nEnter the lenght and width, respectively. \n";
	cin>>l>>w; //consle-input for lenght and width i.e, breadth.
}
void rectangle::area1() //function definition of area1 for class rectangle.
{
	float area=l*w; //simple expression based on the formula for the area of a rectangle.
	cout<<"\nThe area of the given rectangle is "<<area<<" sq-units. \n";
}

void switch1(int x) //function definition of switch-case function named, "switch1".
{
	shape *o1; //create POINTER object from base class.
	circle o4; //create object for circle.
	triangle o5; //create object for triangle.
	rectangle o6; //create object for rectangle.
	
	switch(x) //begin switch-case block.
	{
		case 1: //if circle is chosen.
			cout<<"\nYou have chosen a circle. \n";
			o1=&o4; //assigning address of circle object to base pointer-object.
			o1->entry1(); //base object points to entry function.
			o1->area1(); //base object poits to area function.
			break;
		case 2: //if triangle is chosen.
			cout<<"\nYou have chosen a triangle. \n";
			o1=&o5; //assigning address of triangle object to base pointer-object.
			o1->entry1();
			o1->area1();
			break;
		case 3: //if rectangle is chosen.
			cout<<"\nYou have chosen a rectangle. \n";
			o1=&o6; //assigning address of rectangle object to base pointer-object.
			o1->entry1();
			o1->area1();
			break;
		case 4: //if all three shapes are chosen.
			cout<<"\nYou have chosen all the shapes. \n";
			o1=&o4;
			o1->entry1();
			o1->area1();

			o1=&o5;
			o1->entry1();
			o1->area1();

			o1=&o6;
			o1->entry1();
			o1->area1();
			break;
		default: //if invalid selection is made.
			cout<<"\nInvalid selection, resubmit selection. \n";
			cin>>x; //console-input for new argument.
			switch1(x); //recursive call to switch-case function named, "switch1".
	}
}

