


#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	//Create vector and initialize
	int nub = 250;
	std::vector <int> population(nub, 0);
	population[0] = 1;
	int maxtime = 400;
	//open file
	std::ofstream myOutputFileStream("data.csv");


	//timeloop
	for (int tim = 0; tim < maxtime; ++tim) {

		//Remove comments if you only want the data form t=N/2 onwards
		//if (tim >= nub / 2) { 

		for (int i = 0; i < population.size(); i++) {
			myOutputFileStream << population[i] << ",";
		}
		myOutputFileStream << std::endl;
		//}



		//output current population vector to console, replace nub by 50 if you only want first 50 positions, I prefer seeing the whole thing
		for (int i = 0; i < nub; i++) { std::cout << population[i]; }
		std::cout << "" << std::endl;


		//Vector for next timestep
		std::vector <int> newpopulation(nub, 0);

		//Loop through all the individuals
		for (int i = 0; i < nub; i++) {
			int focal = population[i];
			int left;
			int right;

			//wrap edges
			if (i == 0) {
				left = population[nub - 1];
				right = population[i + 1];
				//std::cout << "first indiv i = "<<i << std::endl;
			}
			if (i == nub - 1) {
				left = population[i - 1];
				right = population[0];
				//std::cout << "last indiv i = "<<i << std::endl;
			}

			//normal case
			if (i > 0 && i < nub - 1) {
				left = population[i - 1];
				right = population[i + 1];
			}

			//update rules
			if (focal == 1) {
				if (left == 1 && right == 1) { newpopulation[i] = 0; }
				if (left == 1 && right == 0) { newpopulation[i] = 1; }
				if (left == 0 && right == 1) { newpopulation[i] = 1; }
				if (left == 0 && right == 0) { newpopulation[i] = 1; }
			}

			if (focal == 0) {
				if (left == 1 && right == 1) { newpopulation[i] = 1; }
				if (left == 1 && right == 0) { newpopulation[i] = 0; }
				if (left == 0 && right == 1) { newpopulation[i] = 1; }
				if (left == 0 && right == 0) { newpopulation[i] = 0; }

			}
		}

		//update the whole population
		population = newpopulation;

	}


	myOutputFileStream.close();




}