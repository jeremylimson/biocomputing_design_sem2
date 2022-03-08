/* 
 * @author Will Smith
 * Coded by Robert F Cooper, Feb 2020
 *
 * Now this is the story all about how,
 * My life got flipped-turned upside down,
 * And I'd like to take a minute, just sit right there,
 * I'll tell you how I became the prince of a town called Bel Air.
 */	
namespace Philadelphia{
	// In West Philadelphia, born and raised
	// On the playground is where I spent most of my days.
	class WestPhila : class Neighborhood{
		private:
			std::location myLocation;
			std::playground playGround;
			// Chillin' out, 
			void chill();
			// maxin', 
			void findMax();
			// relaxin all cool,
			void relax();
		public:
			WestPhila(std::location theLocation);
			// And all shootin' some B-ball outside of the school.
			void shootBasketBall(std::school school);
			// When a couple of guys who were up to no good,
			// Started makin' trouble in my neighborhood.
			void makeTrouble(std::guy guy1, std::guy guy2);
			// I got in one little fight and my mom got scared,
			std::pain fightGuys(std::vector<std::guy> guys);
			// And said "You're movin' with your auntie and uncle in Bel Air."
			void transferLocation(std::location newLocation);
	}
}

namespace LosAngeles{
	class Cab{
		public:
			std::mirror<std::dice> hangingThings;
			std::license_plate cabLabel;
			// I whistled for a cab,
			std::cab call(std::method call);
			/* and when it came near,
			 * The license plate said "fresh" and it had dice in the mirror.
			 * If anything I could say that this cab was rare,
			 */
			Cab(std::license_plate plateNum, std::mirror<std::dice> mirrorHangings, bool rare);
		
			// But I thought "Nah forget it- Yo, home to Bel Air."
			void drive(std::location toLocation);
	}

	class BelAir : class Neighborhood{
		public:
			BelAir(std::location theLocation);
			// I pulled up to the house about seven or eight,
			std::location houseLocation;
			std::house aHouse;
			// and I yelled to the cabby "Yo homes, smell ya later."
			void yell(std::object atObj, std::message words);
			// Looked at my kingdom, I was finally there,
			void look(std::kingdom area);
			// To sit on my throne as the Prince of Bel Air.
			void sit(std::object throne);
	}	
}