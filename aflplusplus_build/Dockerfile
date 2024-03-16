# Use an official AFLplusplus base image
FROM aflplusplus/aflplusplus:latest

# Install git
RUN apk add git 

# Set environment variables based on build arguments
ARG FILE_NAME
ARG SOURCE_FOLDER
ENV FILE_NAME=$FILE_NAME
ENV SOURCE_FOLDER=$SOURCE_FOLDER

# Set the working directory
WORKDIR /afl

# Copy the entrypoint script into the container
COPY entrypoint.sh /afl/entrypoint.sh

# Make the script executable
RUN chmod +x /afl/entrypoint.sh

# Set the entrypoint for the container
ENTRYPOINT ["/afl/entrypoint.sh"]


