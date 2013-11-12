
class Logger
{
public:
    static Logger* getInstance()
    {
        if (_ptr_log == NULL)
            _ptr_log = new Logger(std::cerr);
        return _ptr_log;
    }
    
private:
    Logger(std::basic_ostream& os) : _os(os)
    {
        _ptr_log = NULL;
    }

    static Logger* _ptr_log;
    std::basic_ostream& _os;
};


