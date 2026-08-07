import os

TARGET_MODEL = 'model-max-tasks'
FUNCTION_TEMPLATE_FILE = 'max-tasks-function-template.c'

TARGET_MODEL_WORK_FOLDER = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../taste_models/", TARGET_MODEL, "work"))
FUNCTION_NUMBER_START = 11
FUNCTION_NUMBER_END = 40

# Load the template file content
with open(FUNCTION_TEMPLATE_FILE, 'r') as template_file:
    function_template_content = template_file.read()

# Iterate over all required functions
for function_number in range(FUNCTION_NUMBER_START, FUNCTION_NUMBER_END + 1):

    # Replace the placeholder with the actual function number
    function_content = function_template_content.replace('<FUNCTION_NUMBER>', str(function_number))

    # Define the output file name
    function_name = f'function_{function_number}'
    output_file_name = f'{function_name}.c'
    output_file_dir = os.path.join(TARGET_MODEL_WORK_FOLDER, function_name, "C", "src")
    os.makedirs(output_file_dir, exist_ok=True)
    output_file_path = os.path.join(output_file_dir, output_file_name)

    # Write the generated content to the new file
    with open(output_file_path, 'w') as output_file:
        output_file.write(function_content)

    # Report what we did
    print(f"Generated code file {output_file_path}")

# NOt required anymore. Relates to bug in early script
#    # If there is a .c file with the same name in the function folder, remove it
#    phantom_file_path = os.path.join(TARGET_MODEL_WORK_FOLDER, function_name, output_file_name)
#    if os.path.exists(phantom_file_path):
#        os.remove(phantom_file_path)

# Not required: make skeletons will add this, once the Interface defines it
#    # Also create a .pro file in the function folder
#    pro_file_name = f'{function_name}.pro'
#    pro_file_path = os.path.join(TARGET_MODEL_WORK_FOLDER, function_name, pro_file_name)
#    with open(pro_file_path, 'w') as pro_file:
#        pro_file.write(f"SOURCES += work/{function_name}/C/src/{function_name}.c\n")
#        pro_file.write(f"HEADERS += work/{function_name}/C/src/{function_name}.h\n")
#    print(f"Generated .pro file {pro_file_path}")
