//
// Created by mlabouri on 12/16/21.
//

#ifndef INC_42_ITERATOR_HPP
#define INC_42_ITERATOR_HPP

#include "../utils/stddef.hpp"

namespace ft {

	/** @struct iterator
	 *
	 * @brief https://www.cplusplus.com/reference/iterator/iterator
	 *
	 * Définis la struct de base de l'iterator, avec tout les types membres requis
	 *
	 * @tparam Category < Catégorie de l'iterator, usuellement on y met des iterator_tags
	 * @tparam T < Type sur lequel l'iterator pointe
	 * @tparam Distance < Default: ptrdiff_t. Type entier utilisé pour les operations arithmétiques
	 * @tparam Pointer < Default: T*. Usuellement un pointeur sur type
	 * @tparam Reference < Default: T&. Usuellement une reference sur type
	 *
	 */

	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
	public:
		typedef T         value_type;			/// < @brief Type sur lequel l'iterator pointe (T)
		typedef Distance  difference_type;		/// < @brief Type entier utilisé pour les operations arithmétiques
		typedef Pointer   pointer;				/// < @brief Usuellement un pointeur sur type (T*)
		typedef Reference reference;			/// < @brief Usuellement une reference sur type (T&)
		typedef Category  iterator_category;	/// < @brief Catégorie de l'iterator, usuellement un des iterator_tags
	};

	/** @struct iterator spécialisation de template pour const type
	 *
	 * @brief https://www.cplusplus.com/reference/iterator/iterator
	 *
	 * Définis la struct de base de l'iterator, avec tout les types membres requis.
	 * Spécialisation de template pour const type
	 *
	 * @tparam Category	< Catégorie de l'iterator, usuellement on y met des iterator_tags
	 * @tparam T 		< Type sur lequel l'iterator pointe
	 *
	 */

	template <class Category, class T>
	struct iterator<Category, const T> {
	public:
		typedef const T   value_type;			/// < @brief Type sur lequel l'iterator pointe, en const (const T)
		typedef ptrdiff_t difference_type;		/// < @brief Type entier utilisé pour les operations arithmétiques
		typedef const T*		  pointer;		/// < @brief Usuellement un pointeur sur const type (const T*)
		typedef const T&        reference;		/// < @brief Usuellement une reference sur const type (const T&)
		typedef Category  iterator_category;	/// < @brief Catégorie de l'iterator, usuellement un des iterator_tags
	};
}

#endif //INC_42_ITERATOR_HPP
