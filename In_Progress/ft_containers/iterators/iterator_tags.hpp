//
// Created by mlabouri on 12/16/21.
//

#ifndef INC_42_ITERATOR_TAGS_HPP
#define INC_42_ITERATOR_TAGS_HPP

namespace ft {
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag, public output_iterator_tag{};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
}

#endif //INC_42_ITERATOR_TAGS_HPP
