#include <iostream>
#include <Windows.h>

using namespace std;

class PaintApi {
public:
	PaintApi() {}
	virtual ~PaintApi() {};
	virtual void DrawRectangle(int x, int y, int endx, int endy) = 0;
};

class BlueRectangle : public PaintApi {
public:
	BlueRectangle() {}
	virtual ~BlueRectangle() {}

	virtual void DrawRectangle(int x, int y, int endx, int endy) {
		cout << "Draw Blue Rectangle" << endl << "x = " << x << "y = " << y << "endx = " << endx << "endy = " << endy << endl;
	}
};

class BlackRectangle : public PaintApi {
public:
	BlackRectangle() {}
	virtual ~BlackRectangle() {}

	virtual void DrawRectangle(int x, int y, int endx, int endy) {
		cout << "Draw Black Rectangle" << endl << "x = " << x << "y = " << y << "endx = " << endx << "endy = " << endy << endl;
	}
};

class Figure {
protected:
	PaintApi* api;
public:
	Figure(PaintApi* pApi) {
		api = pApi;
	}

	virtual ~Figure() {
		if (api) delete api;
	}

	virtual void DrawFigure() const = 0;
};

class Rectangle : public Figure {
private:
	int x;
	int y;
	int endx;
	int endy;
public:
	Rectangle(int pX, int pY, int pEndx, int pEndy, PaintApi* pApi) : Figure(pApi) {
		x = pX;
		y = pY;
		endx = pEndx;
		endy = pEndy;
	}

	virtual ~Rectangle() {}

	void DrawFigure()const {
		api->DrawRectangle(x, y, endx, endy);
	}
};

int main()
{
	SetConsoleOutputCP(1251);

	Figure* blackRectangle = new Rectangle(10, 10, 100, 100, new BlackRectangle());
	Figure* blueRectangle = new Rectangle(20, 20, 200, 200, new BlueRectangle());

	blackRectangle->DrawFigure();
	blueRectangle->DrawFigure();

	delete blackRectangle;
	delete blueRectangle;

	return 0;
}