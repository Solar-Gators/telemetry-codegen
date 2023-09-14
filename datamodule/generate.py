import os
import sys
import yaml
from jinja2 import Environment, FileSystemLoader, select_autoescape


def main():
    config_file = sys.argv[1]

    with open(config_file, "r") as f:
        config = yaml.safe_load(f)


    env = Environment(loader=FileSystemLoader(os.path.dirname(os.path.abspath(__file__))))

    cpp_template = env.get_template("cpp/module.cpp")

    for can_message in config["can_messages"]:

        for attribute in can_message["schema"]:
            attribute["bytes"] = 2

        with open(f"{can_message['name']}.cpp", "w") as f:
            file = cpp_template.render(
                moduleName=can_message["name"],
                attributes=can_message["schema"],
            )
            f.write(file)


if __name__ == "__main__":
    main()
