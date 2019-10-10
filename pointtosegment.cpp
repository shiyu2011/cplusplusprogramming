#include<algorithm>
#include<vector>
#include<iostream>
#include<math.h>

#define PI 3.1415926
class point{
	private:
		float x, y;
	public:
		point (float t1, float t2) {x=t1; y=t2;}
		point () {}
		point operator + (point const &p2){
			point pnew;
			pnew.x = this->x+ p2.x;
			pnew.y = this->y+ p2.y;
			return pnew;
		}
		point operator - (point const &p2){
			point pnew;
			pnew.x = this->x- p2.x;
			pnew.y = this->y- p2.y;
			return pnew;
		}
		point trans(point p, float angle){
			point pnew;
			pnew.x = p.x*cos(angle)+p.y*sin(angle);
			pnew.y = -p.x*sin(angle)+p.y*cos(angle);
			return pnew;
		}
		float ppdis(point p1, point p2){
			point tmp = p1 - p2;
			return sqrt(tmp.x*tmp.x + tmp.y*tmp.y);
		}
		float pldis(point p0, point p1, point p2){
			//get angle
			float alpha;
			if(p2.x-p1.x == 0)
				alpha = PI/2;
			else
				alpha = atan((p2.y-p1.y)/(p2.x-p1.x));
			//translate center at p1
			point p0new = p0-p1; 
			point p1new = p1-p1; 
			point p2new = p2-p1;
			p0new = trans(p0new, alpha);
			p1new = trans(p1new, alpha);
			p2new = trans(p2new, alpha);
			if(p0new.x<=0 || p0new.x>=p2new.x)
				return std::min(ppdis(p0new, p1new), ppdis(p0new, p1new));
			else
				return abs(p0new.y);
		}
};

int main(){
	point p0(7, 8);
	point p1(0, 0);
	point p2(10, 200);
	float tmp = p2.pldis(p0, p1, p2);
	std::cout << tmp <<std::endl;
	return 1;
}
