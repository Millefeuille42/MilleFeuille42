//
// Created by mathi on 09-Mar-22.
//

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {
	/** @class stack
	 *
	 * @brief //https://www.cplusplus.com/reference/vector/vector
	 *
	 * @tparam T Le type stocké dans la stack
	 * @tparam Container Default: vector, le type de container utilisé par la stack pour le container sous-jacent
	 */

	template<class T, class Container = vector<T> >
	class stack {
	public:
		/// @typedef Type stocké dans la stack (T)
		typedef T			value_type;
		/// @typedef Type de container utilisé par la stack pour le container sous-jacent (Container)
		typedef Container	container_type;
		/// @typedef Type utilisé pour les entiers
		typedef size_t		size_type;

	protected:
		/// @var c Le conteneur sous-jacent (au quel on fera référence en tant que c)
		container_type c;

	public:

		/** @fn stack constructor
		 *
		 * @brief Constructeur par défaut de stack, possibilité de fournir un container déjà existant de type container_type
		 *
		 * Construit la stack et initialise c à ctnr, ou un container vide si non fournis
		 *
		 * @param ctnr Le container utilisé pour stocker les données, par défaut, un container de type container_type vide
		 */

		explicit stack (const container_type& ctnr = container_type()) {
			c = ctnr;
		}

		/** @fn empty
		 *
		 * @brief Teste si la stack est vide, true si il l'est
		 *
		 * Teste si la stack est vide, true si il l'est, false le cas contraire.
		 * Usuellement, utilise la fonction membre empty de c
		 *
		 * @return true si la stack est vide, false le cas contraire
		 */

		bool empty() const {
			return c.empty();
		};

		/** @fn size
		 *
		 * @brief Retourne la taille de la stack
		 *
		 * Retourne la taille de taille de la stack, usuellement en appelant la fonction size de c
		 *
		 * @return La taille de la stack, de type size_type
		 */

		size_type size() const {
			return c.size();
		}

		/** @fn top
		 *
		 * @brief Retourne le dessus de la stack
		 *
		 * Retourne le dessus de la stack, usuellement en appelant la fonction back de c
		 *
		 * @return une référence sur l'élément au dessus de la stack
		 */

		value_type& top() {
			return c.back();
		}

		const value_type& top() const {
			return c.back();
		}

		/** @fn push
		 *
		 * @brief Ajoute un élément au dessus de la stack
		 *
		 * Ajoute un élément au dessus de la stack, usuellement en appelant la fonction push_back de c
		 *
		 * @param val La valeur a ajouter au dessus de la stack
		 */

		void push(const value_type& val) {
			c.push_back(val);
		}

		/** @fn pop
 		 *
 		 * @brief Retire l'élément au dessus de la stack
 		 *
 		 * Retire l'élément au dessus de la stack, usuellement en appelant la fonction pop_back de c
 		 *
 		 */

		void pop() {
			c.pop_back();
		}

		/** @fn RelOp Opérateurs relationnels
		 *
		 * @brief Opérateurs relationnels entre stacks
		 *
		 * Réalise la comparaison appropriée entre this et rhs
		 *
		 * @param rhs La stack à comparer
		 *
		 * @return Retourne true si la comparaison se valide, false le cas contraire
		 * @{
		 */

		bool operator== (const stack<T,Container>& rhs) const {
			return c == rhs.c;
		}

		bool operator!= (const stack<T,Container>& rhs) const {
			return c != rhs.c;
		}

		bool operator>  (const stack<T,Container>& rhs) const {
			return c > rhs.c;
		}

		bool operator< (const stack<T,Container>& rhs) const {
			return c < rhs.c;
		}

		bool operator<= (const stack<T,Container>& rhs) const {
			return c <= rhs.c;
		}

		bool operator>= (const stack<T,Container>& rhs) const {
			return c >= rhs.c;
		}
		///@}
	};
}

#endif //STACK_HPP
