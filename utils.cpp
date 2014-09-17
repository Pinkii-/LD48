#include "utils.hpp"


dir inverseDir(dir d) {
	switch (d) {
		case up:
			return up;
		case down:
			return down;
		case left:
			return right;
		case right:
			return left;
		default:
			return none;
	}
}
