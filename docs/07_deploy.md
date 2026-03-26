
# Deployment Guide

## Overview
This guide covers deploying the Two Sum implementation project.

## Prerequisites
- Python 3.8+
- pip package manager
- Git

## Installation

```bash
git clone https://github.com/max-shen378/11402_CS5351_Project0.git
cd 11402_CS5351_Project0
pip install -r requirements.txt
```

## Running the Application

```bash
python main.py
```

## Running Tests

```bash
pytest tests/
```

## Environment Configuration
Create a `.env` file if needed for environment variables:

```
DEBUG=False
LOG_LEVEL=INFO
```

## Troubleshooting

| Issue | Solution |
|-------|----------|
| Import errors | Verify Python path and dependencies are installed |
| Tests failing | Ensure test data files are in correct directory |

## Support
Refer to the main README or contact the project maintainer.
