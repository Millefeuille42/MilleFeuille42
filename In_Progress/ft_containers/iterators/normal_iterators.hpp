//
// Created by mlabouri on 12/17/21.
//

#ifndef NORMAL_ITERATOR_HPP
#define NORMAL_ITERATOR_HPP

#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "../utils/exceptions.hpp"
#include "../utils/type_traits.hpp"

namespace ft {
	/** @class normal_random_access_iterator
	 *
	 * Un wrapper vide sur iterator, permettant de simplifier la syntaxe lorsque l'on construit un random_access_iterator
	 *
	 * @inherit Hérite de iterator, avec random_access_iterator_tag comme catégorie
	 *
	 * @tparam type Type sur lequel on souhaite faire pointer l'iterator
	 */

	template<typename type>
	class normal_random_access_iterator : public iterator<std::random_access_iterator_tag, type> {};

	/** @fn trueDistance
     *
     * @brief Fonction interne, calculant la distance entre deux iterators
     *
     * Fonction interne, calculant la distance entre deux iterators, en allant de first a last,
     * le random_access_iterator étant le seul a avoir operator -
     *
     * @tparam InputIterator Le type des deux paramètres, doit être un iterator
     * @param first Un des deux iterator a comparer, usuellement "avant" le second
     * @param last  Un des deux iterator a comparer, usuellement "après" le premier
     * @param tag Paramètre vide ne servant qu'a différencier les plusieurs prototypes de la fonction
     * @return Retourne la distance entre first et last, sous le type membre "difference_type" des iterators fournis
     *
     */

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	iterDistance(InputIterator first, InputIterator last) {
		typename iterator_traits<InputIterator>::difference_type diff = 0;
		for (; first != last ; first++) {
			diff++;
		}
		return diff;
	}

	/** @fn trueDistance
	 *
	 * @brief Fonction interne, permettant de gérer la distance selon le type d'iterator
	 *
	 * Fonction interne, permettant de gérer la distance selon le type d'iterator,
	 * ici la spécialisation pour les non random_access_iterator et les non output_iterator, utilisant la fonction iterDistance
	 *
	 * @tparam InputIterator Le type des deux paramètres, doit être un iterator
	 * @param first Un des deux iterator a comparer, usuellement "avant" le second
	 * @param last  Un des deux iterator a comparer, usuellement "après" le premier
	 * @param tag Paramètre vide ne servant qu'a différencier les plusieurs prototypes de la fonction
	 * @return Retourne la distance entre first et last, sous le type membre "difference_type" des iterators fournis
     *
     */

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::input_iterator_tag tag) {
		(void) tag;
		return iterDistance(first, last);
	}

	/** @fn trueDistance
	 *
	 * @brief Fonction interne, permettant de gérer la distance selon le type d'iterator
	 *
	 * Fonction interne, permettant de gérer la distance selon le type d'iterator,
	 * ici la spécialisation pour les output_iterator, retournant une erreur, la fonction distance ne devant pas fonctionner
	 *
	 * @tparam InputIterator Le type des deux paramètres, doit être un iterator
	 * @param first Un des deux iterator a comparer, usuellement "avant" le second
	 * @param last  Un des deux iterator a comparer, usuellement "après" le premier
	 * @param tag Paramètre vide ne servant qu'a différencier les plusieurs prototypes de la fonction
	 * @return throw une erreur indiquant que l'argument est invalide
	 *
	 */

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::output_iterator_tag tag) {
		(void) tag;
		(void) first;
		(void) last;
		throw ft::invalid_argument();
	}

	/** @fn trueDistance
   	  *
   	  * @brief Fonction interne, permettant de gérer la distance selon le type d'iterator
   	  *
   	  * Fonction interne, permettant de gérer la distance selon le type d'iterator,
   	  * ici la spécialisation pour les non random_access_iterator et les non output_iterator, utilisant la fonction iterDistance
   	  *
   	  * @tparam InputIterator Le type des deux paramètres, doit être un iterator
   	  * @param first Un des deux iterator a comparer, usuellement "avant" le second
   	  * @param last  Un des deux iterator a comparer, usuellement "après" le premier
   	  * @param tag Paramètre vide ne servant qu'a différencier les plusieurs prototypes de la fonction
   	  * @return Retourne la distance entre first et last, sous le type membre "difference_type" des iterators fournis
	  *
  	  */

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::forward_iterator_tag tag) {
		(void) tag;
		return iterDistance(first, last);
	}

	/** @fn trueDistance
  	 *
  	 * @brief Fonction interne, permettant de gérer la distance selon le type d'iterator
  	 *
  	 * Fonction interne, permettant de gérer la distance selon le type d'iterator,
  	 * ici la spécialisation pour les non random_access_iterator et les non output_iterator, utilisant la fonction iterDistance
  	 *
  	 * @tparam InputIterator Le type des deux paramètres, doit être un iterator
  	 * @param first Un des deux iterator a comparer, usuellement "avant" le second
  	 * @param last  Un des deux iterator a comparer, usuellement "après" le premier
  	 * @param tag Paramètre vide ne servant qu'a différencier les plusieurs prototypes de la fonction
  	 * @return Retourne la distance entre first et last, sous le type membre "difference_type" des iterators fournis
  	 *
 	 */

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::bidirectional_iterator_tag tag) {
		(void) tag;
		return iterDistance(first, last);
	}

	/** @fn trueDistance
 	  *
 	  * @brief Fonction interne, permettant de gérer la distance selon le type d'iterator
 	  *
 	  * Fonction interne, permettant de gérer la distance selon le type d'iterator,
 	  * ici la spécialisation pour les random_access_iterator, utilisant operator-
 	  *
 	  * @tparam InputIterator Le type des deux paramètres, doit être un iterator
 	  * @param first Un des deux iterator a comparer, usuellement "avant" le second
 	  * @param last  Un des deux iterator a comparer, usuellement "après" le premier
 	  * @param tag Paramètre vide ne servant qu'a différencier les plusieurs prototypes de la fonction
 	  * @return Retourne la distance entre first et last, sous le type membre "difference_type" des iterators fournis
 	  *
 	*/

	template<class InputIterator>
	static typename iterator_traits<InputIterator>::difference_type
	trueDistance(InputIterator first, InputIterator last, std::random_access_iterator_tag tag) {
		(void) tag;
		if (last - first < 0)
			return first - last;
		return (last - first);
	}

	/** @fn distance
	 *
	 * @brief https://www.cplusplus.com/reference/iterator/distance/
	 *
	 * Donne la distance entre deux itérateurs
	 *
	 * @tparam InputIterator Le type des deux paramètres, doit être un iterator
	 * @param first Un des deux iterator a comparer, usuellement "avant" le second
	 * @param last  Un des deux iterator a comparer, usuellement "après" le premier
	 * @return Retourne la distance entre first et last, sous le type membre "difference_type" des iterators fournis
	 *
	 */

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last) {
		typedef iterator_traits<InputIterator> traits;
		return trueDistance(first, last, typename traits::iterator_category());
	}
}

#endif //NORMAL_ITERATOR_HPP
