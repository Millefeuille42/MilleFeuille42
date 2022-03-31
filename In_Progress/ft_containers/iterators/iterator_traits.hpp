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
		/// @typedef < Catégorie de l'iterator, usuellement un des iterator_tags
		typedef typename _iterator::iterator_category iterator_category;
		/// @typedef < Type sur lequel l'iterator pointe
		typedef typename _iterator::value_type        value_type;
		/// @typedef < Type entier utilisé pour les operations arithmétiques
		typedef typename _iterator::difference_type   difference_type;
		/// @typedef < Usuellement un pointeur sur type
		typedef typename _iterator::pointer           pointer;
		/// @typedef < Usuellement une reference sur type
		typedef typename _iterator::reference         reference;
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
		/// @typedef < Catégorie de l'iterator, un pointeur est un random_access_iterator
		typedef std::random_access_iterator_tag iterator_category;
		/// @typedef < Type du pointeur
		typedef _t                         value_type;
		/// @typedef < Type entier utilisé pour les operations arithmétiques, par défaut ptrdiff_t
		typedef ptrdiff_t                   difference_type;
		/// @typedef < Pointeur sur type
		typedef _t*                        pointer;
		/// @typedef < Référence sur type
		typedef _t&                        reference;
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
		/// @typedef < Catégorie de l'iterator, un pointeur est un random_access_iterator
		typedef std::random_access_iterator_tag iterator_category;
		/// @typedef < Type const du pointeur
		typedef const _t                         value_type;
		/// @typedef < Type entier utilisé pour les operations arithmétiques, par défaut ptrdiff_t
		typedef ptrdiff_t                   difference_type;
		/// @typedef < Pointeur sur const type
		typedef const _t*                  pointer;
		/// @typedef < Référence sur const type
		typedef const _t&                  reference;
	};
}

#endif //INC_42_ITERATOR_TRAITS_HPP
