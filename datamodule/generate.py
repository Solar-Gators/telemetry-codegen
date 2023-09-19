from pathlib import Path
import yaml
from jinja2 import Environment, FileSystemLoader


def main(config_file: str):
    with open(config_file, "r") as f:
        config = yaml.safe_load(f)


    env = Environment(loader=FileSystemLoader(Path(__file__).parent))

    cpp_template = env.get_template("cpp/module.cpp")
    hpp_template = env.get_template("cpp/module.h")
    info_template = env.get_template("cpp/DataModuleInfo.hpp")

    for can_message in config["can_messages"]:

        # ensure the fist letter is caps
        for attribute in can_message["schema"]:
            attribute["name"] = attribute["name"][0].upper() + attribute["name"][1:]

        with open(f"{can_message['name']}.cpp", "w") as f:
            file = cpp_template.render(
                moduleName=can_message["name"],
                attributes=can_message["schema"],
            )
            f.write(file)

        with open(f"{can_message['name']}.hpp", "w") as f:
            file = hpp_template.render(
                moduleName=can_message["name"],
                attributes=can_message["schema"],
            )
            f.write(file)

    with open(f"DataModuleInfo.hpp", "w") as f:
        file = info_template.render(
            canMessages=config["can_messages"],
        )
        f.write(file)


if __name__ == "__main__":
    main(sys.argv[1])
