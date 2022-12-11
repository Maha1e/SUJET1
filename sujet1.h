#define M 7918 //nombre de ligne du document csv
typedef struct Logement Logement; //raccourci
struct Logement //structure contenant un logement
{
	float id;
	float accommodates;
	float bedrooms;
	float bathrooms;
	float beds;
	float price;
	float minimum_nights;
	float maximum_nights;
	float number_of_review;
	float distance;
};
