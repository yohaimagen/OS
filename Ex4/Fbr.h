//
// Created by yohai on 5/26/17.
//

#ifndef EX4_FBR_H
#define EX4_FBR_H


#include <ctime>
#include "CacheAlg.h"


enum POS
{
    OLD,
    NEW,
    MIDDLE
};

class Fbr: public CacheAlg
{
private:
    std::time_t* _last_usage;
    unsigned int* _ref_count;
    POS* _pos;
    int _blocks_num;
    unsigned int _old, _new, _middle;
    std::map<time_t, char*> _oldMap, _newMap, _middleMap;
    struct fbr_blc_data: public blc_data
    {
        std::time_t last_usage;
        unsigned int ref_count;
        POS pos;
    };
public:
    Fbr(int blocks_num, double f_old, double f_new);
    ~Fbr();
    char* get_next_block();
    void update_usage(char* it);
    static bool cmp(const fbr_blc_data &a, const fbr_blc_data &b);
    std::vector<blc_data*> sort_all_blocks();
};


#endif //EX4_FBR_H
