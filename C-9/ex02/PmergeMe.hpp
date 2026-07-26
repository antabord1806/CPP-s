#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sstream>
#include <string>
#include <climits>
#include <algorithm>



class pMerge{
    public:

        pMerge(void){}

        pMerge(const pMerge &copy): _vec(copy._vec), _deque(copy._deque){}

        ~pMerge( void){}

        pMerge &operator=(const pMerge &copy){
                if (this != &copy){
                    _vec = copy._vec;
                    _deque = copy._deque;
                }
            return *this;
        }

        void    handlingInput(std::string &input);

    private:

        typedef std::pair<int, int> Pair;
        typedef std::pair<Pair, Pair> Relation;


        std::vector<Pair> _vec;
        std::deque<Pair> _deque;

        template<typename Container>
        void organizingPairs(Container &container)
        {
            typename Container::iterator it;

            for (it = container.begin(); it != container.end(); ++it)
            {
                if (it->first > it->second)
                    std::swap(it->first, it->second);
            }
        }

        template<typename Container>
        void fordJhonson(Container &sequence)
        {
            if (sequence.size() <= 1)
                return;

            Container winners;
            std::vector<Relation> relations;
            Container mainChain;

            bool hasOdd = false;
            Pair odd;

            if (sequence.size() % 2 != 0)
            {
                hasOdd = true;
                odd = sequence.back();
            }

            for (std::size_t i = 0; i + 1 < sequence.size(); i += 2)
            {
                if (sequence[i].second < sequence[i + 1].second)
                {
                    winners.push_back(sequence[i + 1]);

                    relations.push_back(std::make_pair(sequence[i], sequence[i + 1]));
                }
                else
                {
                    winners.push_back(sequence[i]);

                    relations.push_back(std::make_pair(sequence[i + 1], sequence[i]));
                }
            }

            fordJhonson(winners);

            mainChain = winners;

            if (!winners.empty())
            {
                Pair firstWinner = winners[0];

                for (std::size_t i = 0; i < relations.size(); ++i)
                {
                    if (relations[i].second == firstWinner)
                    {
                        mainChain.insert(
                            mainChain.begin(),
                            relations[i].first
                        );
                        break;
                    }
                }
            }

            std::vector<std::size_t> order;

            order = jacobsthalOrder(winners.size());

            (void)hasOdd;
            (void)odd;
            (void)orderedRelations;

            sequence = mainChain;
        }

        std::vector<std::size_t> jacobsthalOrder(std::size_t count);
};

#endif