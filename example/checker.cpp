#include <cassert>

#include <yaml-cpp/yaml.h>
#include <yavl-cpp/yavl.h>

int main(int argc, char** argv)
{
    YAML::Node validDocument = YAML::LoadFile("./valid.yml");
    YAML::Node invalidDocument = YAML::LoadFile("./invalid.yml");
    YAML::Node schemaDocument = YAML::LoadFile("./schema.yml");

    YAVL::Validator validValidator(schemaDocument, validDocument);
    assert(validValidator.validate() == true);

    YAVL::Validator invalidValidator(schemaDocument, invalidDocument);
    assert(invalidValidator.validate() == false);

    return 0;
}


