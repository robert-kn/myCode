/**
 * Suppose you work as a truck driver, and you have been hired to carry a load of potatoes from Boise, Idaho, to 
 * Minneapolis, Minnesota, a total distance of 2,500 kilometers. You estimate you can average 100 km/hr driving 
 * within the speed limits, requiring a total of 25 hours for the trip.
 * 
 * A. You hear on the news that Montana has just abolished its speed limit, which constitutes 1,500 km of the trip. 
 * Your truck can travel at 150 km/hr. What will be your speedup for the trip?
 * 
 * from amdahl's law, I know that 1/(1-alpha+alpha/k) where alpha represents the fraction of time needed by system
 * therefore alpha in this case will be (15/25) * 100 = 60% i.e. 0.6
 * 
 * k represents the factor by which performance can be improved. In this case it is 1.5 (150/100)
 * 
 * s = told/tnew = 1/(1-alpha+alpha/k) = 25/20 = 1.25 will be the speedup
 * 
 * 
 * B. You can buy a new turbocharger for your truck at www.fasttrucks.com. They stock a variety of models, but the 
 * faster you want to go, the more it will cost. How fast must you travel through Montana to get an overall speedup 
 * for your trip of 1.67×?
 * 
 * 1.67 = 25/x hence x = 25/1.67 = 14.97
 * 
 * since it takes 10 hrs to travel for the remaining 1000 hrs, that leaves 4.97 hrs to travel for 1500 km which means
 * the speed will be approx 302 km/hr
*/