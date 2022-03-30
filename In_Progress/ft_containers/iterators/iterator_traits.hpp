//
// Created by mlabouri on 12/16/21.
//

#ifndef INC_42_ITERATOR_TRAITS_HPP
# define INC_42_ITERATOR_TRAITS_HPP

#include "../utils/stddef.hpp"
#include "../utils/type_traits.hpp"

namespace ft {
	/** @struct iterator_traits
	 * @brief https://www.cplusplus.com/reference/iterator/iterator_traits
	 *
	 * Une structure permettant de récupérer les différents membre types des iterator
	 *
	 * @tparam _iterator < L'iterator dont on veut récupérer les membres types
	 */

	template<typename _iterator>
	struct iterator_traits {
		typedef typename _iterator::iterator_category iterator_category;	/// < @brief Catégorie de l'iterator, usuellement un des iterator_tags
		typedef typename _iterator::value_type        value_type;			/// < @brief Type sur lequel l'iterator pointe
		typedef typename _iterator::difference_type   difference_type;		/// < @brief Type entier utilisé pour les operations arithmétiques
		typedef typename _iterator::pointer           pointer;				/// < @brief Usuellement un pointeur sur type
		typedef typename _iterator::reference         reference;			/// < @brief Usuellement une reference sur type
	};

	/** @struct iterator_traits
 	 * @brief https://www.cplusplus.com/reference/iterator/iterator_traits
 	 *
 	 * Une structure permettant de récupérer les différents membre types des iterator.
 	 * Ici, une spécialisation de template pour les pointeurs
 	 *
 	 * @tparam _t < Un pointeur passé en paramètre
 	 */

	template<typename _t>
	struct iterator_traits<_t*> {
		typedef std::random_access_iterator_tag iterator_category;	/// < @brief Catégorie de l'iterator, un pointeur est un random_access_iterator
		typedef _t                         value_type;				/// < @brief Type du pointeur
		typedef ptrdiff_t                   difference_type;		/// < @brief Type entier utilisé pour les operations arithmétiques, par défaut ptrdiff_t
		typedef _t*                        pointer;					/// < @brief Pointeur sur type
		typedef _t&                        reference;				/// < @brief Référence sur type
	};

	/** @struct iterator_traits
  	 * @brief https://www.cplusplus.com/reference/iterator/iterator_traits
  	 *
  	 * Une structure permettant de récupérer les différents membre types des iterator.
  	 * Ici, une spécialisation de template pour les pointeurs sur const type
  	 *
  	 * @tparam _t < Un pointeur sur const type passé en paramètre
  	 */

	template<typename _t>
	struct iterator_traits<const _t*> {
		typedef std::random_access_iterator_tag iterator_category;	/// < @brief Catégorie de l'iterator, un pointeur est un random_access_iterator
		typedef const _t                         value_type;		/// < @brief Type const du pointeur
		typedef ptrdiff_t                   difference_type;		/// < @brief Type entier utilisé pour les operations arithmétiques, par défaut ptrdiff_t
		typedef const _t*                  pointer;					/// < @brief Pointeur sur const type
		typedef const _t&                  reference;				/// < @brief Référence sur const type
	};
}

#endif //INC_42_ITERATOR_TRAITS_HPP
