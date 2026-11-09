import os
# Increase timeout limits for large downloads (in seconds)
os.environ["HF_HUB_ETAG_TIMEOUT"] = "60"
os.environ["HF_HUB_DOWNLOAD_TIMEOUT"] = "60"

from datasets import load_dataset
import pandas as pd

print("Downloading dataset from Hugging Face (with extended timeout)...")
# If it keeps dropping, you can also add trust_remote_code=True or try streaming=True
dataset = load_dataset("corbt/all-recipes")
df = dataset['train'].to_pandas()

print("Processing data format for C++...")
def format_recipe(text):
    lines = text.strip().split('\n')
    title = lines[0] if len(lines) > 0 else "Untitled Recipe"
    ingredients = ';'.join(lines[1:]) if len(lines) > 1 else ""
    return pd.Series([title, ingredients])

processed_df = df['input'].head(100000).apply(format_recipe)
processed_df.columns = ['title', 'ingredients']

processed_df.to_csv('recipes_subset.csv', index=False, header=False)
print("Successfully generated 'recipes_subset.csv'!")