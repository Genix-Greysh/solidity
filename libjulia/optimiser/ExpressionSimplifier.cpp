/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * Optimiser component that uses the simplification rules to simplify expressions.
 */

#include <libjulia/optimiser/ExpressionSimplifier.h>

#include <libjulia/optimiser/SimplificationRules.h>
#include <libjulia/optimiser/Semantics.h>

#include <libsolidity/inlineasm/AsmData.h>

#include <libsolidity/interface/Exceptions.h>

#include <libdevcore/CommonData.h>

using namespace std;
using namespace dev;
using namespace dev::julia;
using namespace dev::solidity;


void ExpressionSimplifier::visit(Expression& _expression)
{
	ASTModifier::visit(_expression);
	while (auto match = SimplificationRules::findFirstMatch(_expression))
	{
		// Do not apply the rule if it removes non-constant parts of the expression.
		// TODO: The check could actually be less strict than "movable".
		// We only require "Does not cause side-effects".
		if (match->removesNonConstants && !MovableChecker(_expression).movable())
			return;
		_expression = match->action().toExpression(locationOf(_expression));
	}
}
