import os

TARGET_MODEL = 'model-max-functions'
FUNCTION_TEMPLATE_FILE = 'max-functions-function-template.c'

TARGET_MODEL_WORK_FOLDER = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../taste_models/", TARGET_MODEL, "work"))
LAYER_NUMBER_START = 1
LAYER_NUMBER_END = 7
FUNCTION_NUMBER_START = 1
FUNCTION_NUMBER_END = 10

# Load the template file content
with open(FUNCTION_TEMPLATE_FILE, 'r') as template_file:
    function_template_content = template_file.read()

# Iterate over all required functions
for layer_number in range(LAYER_NUMBER_START, LAYER_NUMBER_END + 1):
    for function_number in range(FUNCTION_NUMBER_START, FUNCTION_NUMBER_END + 1):

        # Replace the placeholder with the actual function number
        function_content = function_template_content.replace('<FUNCTION_NUMBER>', str(function_number))
        function_content = function_content.replace('<LAYER_NUMBER>', str(layer_number))

        # Define the output file name
        function_name = f'layer_{layer_number}_f{function_number}'
        output_file_name = f'{function_name}.c'
        output_file_dir = os.path.join(TARGET_MODEL_WORK_FOLDER, function_name, "C", "src")
        os.makedirs(output_file_dir, exist_ok=True)
        output_file_path = os.path.join(output_file_dir, output_file_name)

        # Write the generated content to the new file
        with open(output_file_path, 'w') as output_file:
            output_file.write(function_content)

        # Report what we did
        print(f"Generated code file {output_file_path}")

