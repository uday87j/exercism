#ifndef NUCLEOTIDE_COUNT_H_
#define NUCLEOTIDE_COUNT_H_

#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <exception>

namespace dna   {

    typedef std::map<char, int> ci_map_t;

    void print_map(const ci_map_t& g)    {
        for(auto& m : g)    {
            std::cout << m.first << ":\t" << m.second << std::endl;
        }
    }

    class counter   {
        public:
            counter(std::string str = "")
                : m_str(str)    {
                    m_cimap['A']    = 0;
                    m_cimap['T']    = 0;
                    m_cimap['C']    = 0;
                    m_cimap['G']    = 0;
                    for(auto& c : m_str)    {
                        if(valid_char(c))   {
                            ++m_cimap[c];
                        }
                        else    {
                            throw std::invalid_argument("Arg is not a DNA strand");//Make this work!
                        }
                    }
                    //print_map(m_cimap);
                }
            ci_map_t nucleotide_counts() const {
                return m_cimap;
            }
            int count(const char c) const   {
                return m_cimap.at(c);
            }
        private:
            bool valid_char(const char c)   {
                return ((c == 'A') || (c == 'C') || (c == 'T') || (c == 'G'));                    
            }
            std::string m_str;
            ci_map_t m_cimap;
    };
}
#endif
