/**
*
* @id cpp-blog/example-queries/destructor-not-virtual
* @name Base Class with non-virtual destructor
* @description Finds base classes where the destructor is not virtual and the derived class has a destructor
* @kind problem
* @problem.severity recommendation
*
*/
import cpp

from Class base, Destructor d1, Class derived, Destructor d2
where derived.getABaseClass+() = base
  and d1.getDeclaringType() = base
  and d2.getDeclaringType() = derived
  and not d1.isVirtual()
select d1, "This destructor should probably be virtual."