/**
 * @author      Takashi Matsushita
 * Created:     11 Nov 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esObjectHandle_hh
#define tmEventSetup_esObjectHandle_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include "tmGrammar/Object.hh"
#include "tmTable/tmTable.hh"
#include "tmEventSetup/esObject.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{

/**
 *  This class implements data structure for Object
 */
class esObjectHandle : public esObject
{
  public:
    // ctor
    esObjectHandle() { };
    esObjectHandle(const Object::Item& item);
    esObjectHandle(const Object::Item& item,
                   const tmtable::Table& cuts_in_algo);

    // dtor
    virtual ~esObjectHandle() { };

    /** initialise the instance with Object::Item instance
     *
     * @param item [in] Object::Item instance */
    void init(const Object::Item& item);

    /** set external channel id
     *
     * @param item [in] external map<name, id>
     */
    void setExternalChannelId(const std::map<std::string, unsigned int>& map);

    /** print the contents of instance */
    void print() const;
    static void print(const esObject& object);

};

} // namespace tmeventsetup
#endif // tmEventSetup_esObjectHandle_hh
/* eof */
