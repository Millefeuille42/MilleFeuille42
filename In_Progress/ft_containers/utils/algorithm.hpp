//
// Created by mathi on 10-Mar-22.
//

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft {

	/** @fn equal
	 *
	 * @brief https://www.cplusplus.com/reference/algorithm/equal/
	 *
	 * Compare les éléments de la séquence [first1,last1) a ceux de la séquence commençant à first2,
	 * retourne true si tous les éléments sont égaux.
	 * Les éléments sont comparés a l'aide de la fonction operator ==
	 *
	 * @tparam InputIterator1 Le premier type donné en paramètre, doit être un itérateur
	 * @tparam InputIterator2 Le second type donné en paramètre, doit être un itérateur
	 * @param first1 Iterator initial de la première sequence a comparer, inclus
	 * @param last1 Iterator final de la première sequence a comparer, non inclus
	 * @param first2 Iterator initial de la seconde sequence a comparer, inclus
	 * @return true si tout les éléments de la séquence [first1,last1) sont égaux a ceux de la séquence commençant à first2, false le cas contraire
	 */

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		for (; first1 != last1; first1++) {
			if (*first1 != *first2)
				return false;
			first2++;
		}
		return true;
	}

	/** @fn equal
     *
     * @brief https://www.cplusplus.com/reference/algorithm/equal/
     *
     * Compare les éléments de la séquence [first1,last1) a ceux de la séquence commençant à first2,
     * retourne true si tous les éléments sont égaux.
     * Les éléments sont comparés utilisant la fonction de comparaison donnée dans le paramètre pred
     *
     * @tparam InputIterator1 Le premier type donné en paramètre, doit être un itérateur
     * @tparam InputIterator2 Le second type donné en paramètre, doit être un itérateur
     * @tparam BinaryPredicate Le type de fonction utilisé pour la comparaison
     * @param first1 Iterator initial de la première sequence a comparer, inclus
     * @param last1 Iterator final de la première sequence a comparer, non inclus
     * @param first2 Iterator initial de la seconde sequence a comparer, inclus
     * @param pred La fonction utilisée pour la comparaison
     * @return true si tout les éléments de la séquence [first1,last1) sont égaux a ceux de la séquence commençant à first2, false le cas contraire
     */

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		for (; first1 != last1; first1++) {
			if (!pred(*first1, *first2))
				return false;
			first2++;
		}
		return true;
	}

	/** @fn lexicographical compare
	 *
	 * @brief https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
     *
     * Une comparaison lexicographique est le type de comparaison généralement utilisé pour trier les mots par ordre alphabétique dans les dictionnaires ;
     * Il s'agit de comparer séquentiellement les éléments qui ont la même position dans les deux plages les uns avec les autres jusqu'à ce qu'un élément ne soit pas équivalent à l'autre.
     * Le résultat de la comparaison de ces premiers éléments non concordants est le résultat de la comparaison lexicographique.
     * Si les deux séquences sont égales jusqu'à ce que l'une d'elles se termine, la séquence la plus courte est lexicographiquement inférieure à la plus longue.
	 * Renvoie true si la séquence [first1,last1) est lexicographiquement strictement inférieure à la plage [first2,last2).
	 *
     * @tparam InputIterator1 Le premier type donné en paramètre, doit être un itérateur
     * @tparam InputIterator2 Le second type donné en paramètre, doit être un itérateur
     * @param first1 Iterator initial de la première sequence a comparer, inclus
     * @param last1 Iterator final de la première sequence a comparer, non inclus
     * @param first2 Iterator initial de la seconde sequence a comparer, inclus
	 * @param last2 Iterator final de la seconde sequence a comparer, non inclus
	 * @return true si la première sequence est lexicographiquement strictement inférieure à la seconde, faux le cas contraire
	 */

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		for (; first1 != last1; first1++) {
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2) {
				return true;
			}
			first2++;
		}
		return (first2 != last2);
	}

	/** @fn lexicographical compare
 	 *
 	 * @brief https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
 	 *
 	 * Une comparaison lexicographique est le type de comparaison généralement utilisé pour trier les mots par ordre alphabétique dans les dictionnaires ;
 	 * Il s'agit de comparer séquentiellement les éléments qui ont la même position dans les deux plages les uns avec les autres jusqu'à ce qu'un élément ne soit pas équivalent à l'autre.
 	 * Le résultat de la comparaison de ces premiers éléments non concordants est le résultat de la comparaison lexicographique.
 	 * Si les deux séquences sont égales jusqu'à ce que l'une d'elles se termine, la séquence la plus courte est lexicographiquement inférieure à la plus longue.
 	 * Renvoie true si la séquence [first1,last1) est lexicographiquement strictement inférieure à la plage [first2,last2).
 	 *
 	 * @tparam InputIterator1 Le premier type donné en paramètre, doit être un itérateur
 	 * @tparam InputIterator2 Le second type donné en paramètre, doit être un itérateur
 	 * @tparam BinaryPredicate Le type de fonction utilisé pour la comparaison
 	 * @param first1 Iterator initial de la première sequence a comparer, inclus
 	 * @param last1 Iterator final de la première sequence a comparer, non inclus
 	 * @param first2 Iterator initial de la seconde sequence a comparer, inclus
 	 * @param last2 Iterator final de la seconde sequence a comparer, non inclus
 	 * @param pred La fonction utilisée pour la comparaison
 	 * @return true si la première sequence est lexicographiquement strictement inférieure à la seconde, faux le cas contraire
     */

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
		for (; first1 != last1; first1++) {
			if (first2 == last2 || comp(*first2 < *first1))
				return false;
			else if (comp(*first1 < *first2)) {
				return true;
			}
			first2++;
		}
		return (first2 != last2);
	}
}

#endif //ALGORITHM_HPP
