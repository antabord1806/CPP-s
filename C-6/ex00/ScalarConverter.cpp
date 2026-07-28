    #include "ScalarConverter.hpp"

    ScalarConverter::ScalarConverter(){}

    ScalarConverter::ScalarConverter(const ScalarConverter &copy){
        (void)copy;
    }

    ScalarConverter::~ScalarConverter(){}

    ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
    {
        (void)copy;
        return *this;
    }

    bool    ScalarConverter::IsChar(const std::string& literal)
    {
        return (
            literal.length() == 1 &&
            !std::isdigit(static_cast<unsigned char>(literal[0]))
        );
    }

    bool    ScalarConverter::IsInt(const std::string &literal){
        std::string::size_type i = 0;
        if (literal[i] == '+' || literal[i] == '-')
                i++;
        if (i == literal.length())
            return false;
        while (i < literal.length()){
            if (!std::isdigit(static_cast<unsigned char>(literal[i]))){
                return false;
            }
            i++; 
        }

        return true;
    }

    bool ScalarConverter::IsFloat(const std::string &literal)
    {
        std::string::size_type i = 0;
        int dot = 0;

        if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
            return false;

        if (literal[i] == '+' || literal[i] == '-')
            i++;

        if (i >= literal.length() - 1)
            return false;

        while (i < literal.length() - 1)
        {
            if (literal[i] == '.')
            {
                if (dot > 1)
                    return false;
                dot++;;
            }
            else if (!std::isdigit(static_cast<unsigned char>(literal[i])))
                return false;

            i++;
        }

        return true;
    }

    bool ScalarConverter::IsDouble(const std::string &literal)
    {
        std::string::size_type i = 0;
        bool dot = false;

        if (literal.length() < 2)
            return false;

        if (literal[i] == '+' || literal[i] == '-')
            i++;

        while (i < literal.length())
        {
            if (literal[i] == '.')
            {
                if (dot)
                    return false;
                dot = true;
            }
            else if (!std::isdigit(static_cast<unsigned char>(literal[i])))
                return false;

            i++;
        }

        return dot;
    }

    bool ScalarConverter::IsPseudo(std::string const &str)
    {
        return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff"
            || str == "-inf" || str == "-inff");
    }

    void     ScalarConverter::convert(const std::string &literal){
        if (literal.empty()){
            std::cout <<"Empty!" << std::endl;
            return ;
        }

        int count = 0;

        for (size_t i = 0; i < literal.length(); i++)
        {
            if (count > 1){
                std::cout << "Too many dots!" << std::endl;
                return ;
            }
            if (literal[i] == '.')
                count++;
        }

        if ((literal[0] == '+' || literal[0] == '-' || literal[0] == '.') && !literal[1])
            std::cerr << "Ivalid!" << std::endl;
        
        if (IsChar(literal)){
            std::cout << "Is char" << std::endl;
            char c = literal[0];
            std::cout << "Char: " << literal << std::endl;
            std::cout << "Int: " << static_cast<int>(c) << std::endl;
            std::cout << "Float: " << static_cast<int>(c) << ".0f" << std::endl;
            std::cout << "Double: " << static_cast<int>(c) << ".0" << std::endl;
            std::cout << "Pseudo: " << "Impossible" << std::endl;
        }

        else if (IsInt(literal)){
            std::cout << "Is int" << std::endl;
            double n = 0;
            std::stringstream stream(literal);
            stream >> n;
            std::cout << "Char: ";
            if (!std::isprint(static_cast<unsigned char>(n)))
                std::cout << "Non displayable" << std::endl;
            else
                std::cout << static_cast<char>(n) << std::endl;
            std::cout << "Int: " << n << std::endl;
            std::cout << "Float: " << n << ".0f" << std::endl;
            std::cout << "Double: " << n << ".0" << std::endl;
        }

        else if (IsPseudo(literal)){
            std::cout << "Is pseudo" << std::endl;
            std::cout << "Char: impossible" << std::endl;
            std::cout << "Int: impossible" << std::endl;
            if (literal == "nan" || literal == "+inf" || literal == "-inf"){
                std::cout << "Float: " << literal << "f" << std::endl;
                std::cout << "Double: " << literal << std::endl;
                return;
            }
            std::cout << "Float: " << literal << std::endl;
            std::cout << "Double: " << literal.substr(0, literal.length() - 1) << std::endl;
        }
        
        else if (IsFloat(literal)){     
            std::cout << "Is float" << std::endl;
            try{
                std::stringstream stream(literal);
                double n = 0;
                stream >> n;
                if (stream.fail())
                    throw std::runtime_error("Rip!");
                float f = static_cast<float>(n);
                std::cout << "Char: ";
                if (f < 0 || f > 127)
                    std::cout << "impossible" << std::endl;
                else if (!std::isprint(static_cast<unsigned char>(f)))
                    std::cout << "Non displayable" << std::endl;
                else{
                    char c = static_cast<char>(f);
                    std::cout << c << std::endl;
                }
                std::cout << "Int: ";
                if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
                    std::cout << "impossible" << std::endl;
                else{
                    int tmp = static_cast<int>(f);
                    std::cout << tmp << std::endl;
                }
                std::cout << "Float: ";
                if (n == static_cast<double>(f)){
                    if (n < static_cast<double>(INT_MIN) || n > static_cast<double>(INT_MAX))
                        std::cout << std::scientific << n << ".0f" << std::endl;
                    else
                        std::cout << std::fixed << std::setprecision(1) << n << "f" << std::endl;
                }
                else
                    std::cout << f << "f" << std::endl;
                std::cout << "Double: ";
                if (f == static_cast<int>(f)){
                    if (n < static_cast<double>(INT_MIN) || n > static_cast<double>(INT_MAX))
                        std::cout << std::scientific << n << std::endl;
                    else
                        std::cout << std::fixed << std::setprecision(1) << n << std::endl;
                }
                else
                    std::cout << f << std::endl;
            }
            catch(std::exception &e){
                std::cout << "Error: " << std::endl;
            }
            
        }
        else if (IsDouble(literal)){
            std::cout << "Is double" << std::endl;
            try{
                std::stringstream stream(literal);
                double n = 0;
                stream >> n;
                if (stream.fail() || n < static_cast<double>(INT_MIN) || n > static_cast<double>(INT_MAX))
                    throw std::runtime_error("Rip!");
                std::cout << "Char: ";
                if (n < 0 || n > 127)
                    std::cout << "impossible" << std::endl;
                else if (!std::isprint(static_cast<unsigned char>(n)))
                    std::cout << "Non displayable" << std::endl;
                else{
                    char c = static_cast<char>(n);
                    std::cout << c <<std::endl;
                }
                std::cout << "Int: ";
                if (n < static_cast<double>(INT_MIN) || n > static_cast<double>(INT_MAX))
                    std::cout << "impossible" << std::endl;
                else{
                    int tmp = static_cast<int>(n);
                    std::cout << tmp << std::endl;
                }
                std::cout << "Float: ";
                std::cout << std::fixed << std::setprecision(1) <<static_cast<float>(n) << "f" << std::endl;
                std::cout << "Double: " << std::fixed << std::setprecision(1) << n << std::endl;
            }
            catch(std::exception &e){
                std::cout << "Error: invalid conversion" << std::endl;
            }
        }

        else
            std::cout << "Invalid output" << std::endl;
    }

