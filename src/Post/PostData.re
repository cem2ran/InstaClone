type location = {
  city: option(string),
  country: option(string),
};

module GetPhotoByIdGQL = [%graphql
  {|
query getPhotoById($id: ID!, $width: Int, $height: Int){
  getPhotoById(id: $id, width: $width, height: $height){
    id
    color
    user {
      id
      name
      username
      bio
      profile_image {
        small
      }
      portfolio_url
      total_photos
      followers_count
      following_count
    }
    location @bsRecord{
      city
      country
    }
    urls {
      regular
    }
    likes
    liked_by_user
    description
  }
}
|}
];

module GetPhotoByIdQuery = ReasonApolloHooks.Query.Make(GetPhotoByIdGQL);
