#include "lib/Duck/MallardDuck.h"
#include "lib/Duck/RedHeadDuck.h"
#include "lib/Duck/RubberDuck.h"
#include "lib/Duck/DecoyDuck.h"
#include "lib/Duck/ModelDuck.h"
#include "lib/DuckFunctions.h"

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	PlayWithDuck(redheadDuck);

	modelDuck.SetFlyBehavior(flyWithWings);
	PlayWithDuck(modelDuck);

	return EXIT_SUCCESS;
}
