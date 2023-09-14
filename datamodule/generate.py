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

        cpp_template.render(
            moduleName=can_message["name"]
        )


if __name__ == "__main__":
    main()
