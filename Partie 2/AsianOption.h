#ifndef ASIANOPTION_H
#define ASIANOPTION_H

#include "Option.h"
#include <vector>

class AsianOption : public Option {
private:
    double _strike;                      
    std::vector<double> Time_steps;      
protected:
    enum class optionType { call, put }; 
    virtual optionType GetOptionType() const = 0; 
    double getStrike() const;            

public:
    AsianOption();
    AsianOption(double, double, const std::vector<double>&);
    
    double payoffPath(std::vector<double>& prices) const override;
    const std::vector<double>& getTimeSteps() const;
	bool isAsianOption() const override ;
	~AsianOption();
};

#endif
