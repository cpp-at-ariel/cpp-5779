#pragma once
/**
 * Header file for playing bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include "Chooser.hpp"
#include "Guesser.hpp"

namespace bullpgia {
	/**
	 * Run a game of bull-pgia.
	 * @param chooser the player who chooses the secret string.
	 * @param guesser the player who has to guess the string.
	 * @param length the number of chars in the string.
	 * @param maxTurns the maximum number of times the guesser may guess.
	 * @return the number of turns it took guesser to guess the string chosen by chooser.
	 *  If guesser cannot guess the real string in maxTurns turns, 
	 *     then the return value is maxTurns+1.
	 */
	uint play(Chooser& chooser, Guesser& guesser, uint length, uint maxTurns);
}
