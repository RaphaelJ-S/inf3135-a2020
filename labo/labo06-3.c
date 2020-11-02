#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

struct Point_s {
  double x;
  double y;
};

struct Segment_s {
  struct Point_s p1;
  struct Point_s p2;
};

struct Triangle_s {
  struct Point_s points[3];
};

void initialiserSegment(struct Segment_s *segment, double x1, double y1, double x2, double y2);

double longueurSegment(const struct Segment_s *segment);

void initialiserTriangle(struct Triangle_s *triangle, 
				double x1, double y1, 
				double x2, double y2, 
				double x3, double y3);
double perimetreTriangle(const struct Triangle_s *triangle);


int main(int argc, char **argv) {
  const struct Segment_s seg;
  void *p = (struct Segment_s *) malloc(sizeof(seg)); 
  initialiserSegment(p, 12.4, 4.2, 7.1, 9.7);
  printf("\n\nlongueur du segment : %f \n\n", longueurSegment(p));

  free(p);
}

void initialiserTriangle(struct Triangle_s *triangle, double x1, double y1,
						double x2, double y2,
						double x3, double y3) {

}

double longueurSegment(const struct Segment_s *segment) {

  return (sqrt (pow((segment->p1.x - segment->p2.x), 2) + (pow((segment->p1.y - segment->p2.y), 2)))); 
}
void initialiserSegment(struct Segment_s *segment, double x1, double y1, double x2, double y2) {
  segment->p1.x=x1;
  segment->p1.y=y1;
  segment->p2.x=x2;
  segment->p2.y=y2;
  printf("\nPremier point : x = %f, y = %f \nDeuxieme point : x = %f, y = %f \n\n",segment->p1.x, segment->p1.y, segment->p2.x, segment->p2.y);
}
